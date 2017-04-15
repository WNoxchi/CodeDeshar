; SICP_1.33   | Start:  18-Dec-2015 14:36   |   Finish: 18-Dec-2015 15:29
;
; You can make <accumulate> even more general by introducing a filter on the terms to be combined.
;   --> combine only those terms derived from values in the range that satisfy a specified condition.
; <filtered-accumulate> takes same args as <accumulate>, + a predicate of 1 argument that specifies the filter.
; Write <filtered-accumulate> as a proc.
; A:  Express the sum of the squares of the prime numbers in interval a to b using <fil..-acc..>
; B:  Express the product of all (+) ints < n that are relatively prime to n. (ints i < n s.t. GCD(i,n) = 1).

(define (accumulate combiner null-value term a next b)
  (if (> a b)
      null-value
      (combiner (term a) (accumulator null-value term (next a) next b))))

(define (filtered-accumulate filter combiner null-value term a next b)
  (if (> a b)
      null-value
      (combiner (term a) (accumulator null-value term (next a) next b))))

; I have no idea how to implement a filter. What's a filter? Isn't the job of combining only terms derived in a specified range already handled by the (if (> a b) null-value) statement?
; Or is that what the filter is supposed to do? hmmm. How would I write that s.t. it works as an argument?

(define (filtered-accumulate filter combiner null-value term a next b)
  (<<filter>>
      null-value
      (combiner (term a) (accumulator null-value term (next a) next b))))

; So then <<filter>> is going to be some sort of operator, not a function:

(define (filtered-accumulate filter combiner null-value term a next b)
  (if (filter a b)
      null-value
      (combiner (term a) (accumulator null-value term (next a) next b))))

; Time to check.
; OK, I was close. It is:

(define (filtered-accumulate filter combiner null-value term a next b)
  (if (filter a b)
      null-value
      (if (filter a)
          (combiner (term a) (accumulator filter combiner null-value term (next a) next b))
          (filtered-accumulate filter combiner null-value term (next a) next b))))

; Checking behavior, we'll use this filtered-accumulate proc to sum the square of primes in a given range,
; <<fast-prime?>> from 1.22-1.23 will be the filtering function:

(define (fast-prime? n)
   (define (smallest-divisor n)
      (define (find-divisor n test-divisor)
         (define (next x)
            (if (= x 2) 3 (+ x 2)))
         (define (divides? a b)
            (= (remainder b a) 0))
         (cond ((> (square test-divisor) n) n)
               ((divides? test-divisor n) test-divisor)
               (else (find-divisor n (next test-divisor)))))
      (find-divisor n 2))
   (= n (smallest-divisor n)))

 ; Putting that into the filtered accumulator proc:

(define (sum-squared-primes-filacc a b)
  (filtered-accumulate fast-prime? + 0 square a inc b)) ; filter = <<fast-prime?>>, combiner = [+] (summation), null = 0 (summation), term = squaring, next = inc

(define (inc x) (+ x 1))
(define (square x) (* x x))

; At this point, my implementation does not generate correct answers. Checking in interpreter with online solution...
; Mistake was: I had "filter" in for ">" on the first if conditional.

; Full working implementation below:
;-----------------------------------------------------------
(define (filtered-accumulate filter combiner null-value term a next b)
  (if (> a b)
      null-value
      (if (filter a)
          (combiner (term a)
                    (filtered-accumulate filter combiner null-value term (next a) next b))
          (filtered-accumulate filter combiner null-value term (next a) next b))))

(define (fast-prime? n)
   (define (smallest-divisor n)
      (define (find-divisor n test-divisor)
         (define (next x)
            (if (= x 2) 3 (+ x 2)))
         (define (divides? a b)
            (= (mod b a) 0))
         (cond ((> (square test-divisor) n) n)
               ((divides? test-divisor n) test-divisor)
               (else (find-divisor n (next test-divisor)))))
      (find-divisor n 2))
   (= n (smallest-divisor n)))

(define (sum-squared-primes-filacc a b)
  (filtered-accumulate fast-prime? + 0 square a inc b))

(define (inc x) (+ x 1))
(define (square x) (* x x))
;-----------------------------------------------------------
; B:  Product of all [+] ints < n that are relatively prime to n:

(define (gcd a b)
    (if (= b 0)
        a
        (gcd b (mod a b))))

(define (gcdprime i n)
  (if (= (mod n i) 1)
      i
      (gcdprime (+ i 1) n)))

(define (filtered-accumulate filter combiner null-value term a next b)
  (if (> a b)
      null-value
      (if (filter a)
          (combiner (term a)
                    (filtered-accumulate filter combiner null-value term (next a) next b))
          (filtered-accumulate filter combiner null-value term (next a) next b))))
;
(define (prodrelprimes a b)
  (filtered-accumulate gcdprime * 1 identity a inc b))

(define (identity x) x)
(define (inc x) (+ x 1))

;---------------------------------------
; OK.. this exploded in my face in the interpreter. Checking solution...
; Will use <<gcd>> to write <<coprime?>>
; <<coprime?>> takes 2 args, but <<filtered-accumulate>> expects it to take 1, so <<coprime?>> will get it's [n] input from <<product-coprimes>>

(define (product-coprimes n)
  (define (coprime? i)
    (= 1 (gcd i n)))
  (filtered-accumulate coprime? * 1 identity 1 inc (- n 1)))
;-----------------------------
; Putting that together below:
;-----------------------------
(define (gcd a b)
    (if (= b 0)
        a
        (gcd b (mod a b))))

(define (filtered-accumulate filter combiner null-value term a next b)
  (if (> a b)
      null-value
      (if (filter a)
          (combiner (term a)
                    (filtered-accumulate filter combiner null-value term (next a) next b))
          (filtered-accumulate filter combiner null-value term (next a) next b))))

(define (product-coprimes n)
  (define (coprime? i)
    (= 1 (gcd i n)))
  (filtered-accumulate coprime? * 1 identity 1 inc (- n 1)))

(define (identity x) x)
(define (inc x) (+ x 1))

; It works!

;(product-coprimes 3)
;=> 2
;(product-coprimes 4)
;=> 3
;(product-coprimes 5)
;=> 24
;(product-coprimes 6)
;=> 5
;(product-coprimes 7)
;=> 720
;(product-coprimes 10)
;=> 189
;(product-coprimes 11)
;=> 3628800

; Checking & help reference: http://www.billthelizard.com/2010/05/sicp-exercise-133-filtered-accumulator.html
; -*- mode:scheme;-*-

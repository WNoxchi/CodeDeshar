; will have to come back to this if I can get a Scheme interpreter working with (runtime) or (current-inexact-milliseconds)
; reference: http://www.billthelizard.com/2010/02/sicp-exercise-122-timed-prime-test.html
; >> maybe find out how to install Racket? Or boot up a Unix system?

; SICP 1.21
; use smallest-divisor proc to find smallest divisor of 199, 1999, 19,999

(define (smallest-divisor n) (find-divisor n 2))

(define (find-divisor n test-divisor)
  (cond ((> (square test-divisor) n) n)
        ((divides? test-divisor n) test-divisor)
        (else (find-divisor n (+ test-divisor 1)))))

(define (divides? a b) (= (mod b a) 0))
(define (square n) (* n n))

(define (prime? n)
  (= n (smallest-divisor n)))

;------------------

; SICP 1.22
; following procedure checks if n is prime, & how much time taken to test
; Do the times taken follow the expected O(sqrt(10)) increase?

(define (search-for-primes start end)
   (if (even? start)
       (search-for-primes (+ start 1) end)
       (cond ((< start end) (timed-prime-test start)
                            (search-for-primes (+ start 2) end)))))

(define (even? n)
   (= (remainder n 2) 0))

;------------------

(define (timed-prime-test n)
  (newline)
  (display n)
  (start-prime-test n (runtime)))

(define (start-prime-test n start-time)
  (if (prime? n)
      (report-prime (- (runtime) start-time))))

(define (report-prime elapsed-time)
  (display " *** ")
  (display elapsed-time))

; necessary support definitions for (prime?)

(define (smallest-divisor n) (find-divisor n 2))

(define (find-divisor n test-divisor)
  (cond ((> (square test-divisor) n) n)
        ((divides? test-divisor n) test-divisor)
        (else (find-divisor n (+ test-divisor 1)))))

(define (divides? a b) (= (mod b a) 0))
(define (square n) (* n n))

(define (prime? n)
  (= n (smallest-divisor n)))

;------------------
; The following code works on the codepad.org Scheme interpreter:
; still low-res for small numbers on fast systems...

(define (smallest-divisor n)
   (find-divisor n 2))

(define (find-divisor n test-divisor)
   (cond ((> (square test-divisor) n) n)
         ((divides? test-divisor n) test-divisor)
         (else (find-divisor n (+ test-divisor 1)))))

(define (divides? a b)
   (= (remainder b a) 0))

(define (square x)
   (* x x))

(define (prime? n)
   (= n (smallest-divisor n)))

(time
  (display (prime? 10000000019))
  (newline))

; Output:
; #t
; cpu time: 118 real time: 128 gc time: 66

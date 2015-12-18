; SICP_1.23
; (smallest-divisor) does needless testing of even divisors > 2.
; define (next) tht returns 3 if input = 2, otherwise returns its input + 2
; modify (smallest-divisor) to use (next test-divisor) instead of (+ test-divisor 1)
; Run the timed-prime-test and note the difference in time w/ old ver.

; For runtimes, see: http://www.billthelizard.com/2010/02/sicp-exercise-123-improved-prime-test.html

(define (smallest-divisor n) (find-divisor n 2))

(define (find-divisor n test-divisor)
  (cond ((> (square test-divisor) n) n)
        ((divides? test-divisor n) test-divisor)
        (else (find-divisor n (next test-divisor)))))

(define (divides? a b) (= (mod b a) 0))
(define (square n) (* n n))

(define (prime? n)
  (= n (smallest-divisor n)))

(define (next n)
  (if (= n 2) 3 (+ n 2)))

;--------------------------------------
; SICP_1.24
; modify (timed-prime-test) to use (fast-prime?) (Fermat Method)
; test each of previous 12 primes, and note time difference
; If using SISC interpreter (I've been unsuccessful so far), (current-inexact-milliseconds) can be substituted for (runtime)
; For increased randomness, import library: (require (lib "27.ss" "srfi")) and replace (random n) with (random-integer n)
; Reference: http://www.billthelizard.com/2010/02/sicp-exercise-124-fermat-test.html


(define (timed-prime-test n)
  (newline)
  (display n)
  (start-prime-test n (runtime)))

(define (start-prime-test n times start-time)
  (if (fast-prime? n 200)
      (report-prime (- (runtime) start-time))))

(define (report-prime elapsed-time)
  (display " *** ")
  (display elapsed-time))

(define (fast-prime? n times)
  (cond ((= times 0) true)
        ((fermat-test n) (fast-prime? n (- times 1)))
        (else false)))
(define (fermat-test n)   ; **** NOTE: fermat-test only calls 'n', bc 'a' is handled by (random)
  (define (try-it a)
    (= (expmod a n n) a))
  (try-it (+ 1 (random (- n 1)))))

(define (expmod base exp m)
  (cond ((= exp 0) 1)
        ((even? exp)
         (remainder
          (square (expmod base (/ exp 2))
          m))
        (else
         (remainder
          (* base (expmod base (- exp 1) m))
          m)))))

(define (square n) (* n n))
(define (even? n) (= (remainder n 2) 0))

;--------------------------------------
; SICP_1.25
; See footnote #46, p68, SICP.


;--------------------------------------
; SICP_1.26
; Why does using explicit multiplication in (expmod) proc result in an O(n) prcs, whereas using squaring results in O(Log n) ?
; >>  Xjunda alcha: repeated squaring increases exponentially greater than repeated multiplication by self.
; This is the difference between (aldashna: x^2) increasing the exponent by 1 each stage, or doubling it. Doubling (result of squaring) is much faster.
; >> maybe I'm wrong?
; >>>> replacing call to square w explicity multiplication changes (expmod) from a linear recursive prcss into tree recursion -- resulting in an exponential growth in recursive calls to (expmod) instead of doubling at each step.

;--------------------------------------
; SICP_1.27
; Demonstrate that the Carmichael numbers really do fool the Fermat test.
; Write a proc that takes an integer n and tests whether a^n is congruent to a modulo n for every a < n, and try it on the Carmichael numbers.


(define (fermat-test-run n)
  (define (fermatiter a)  ; def iter w/ only a --- no n
    (cond ((= a 1) #t)
          ((not (fermat-test n a)) #f)  ; input n & a, not just a
          (else (fermatiter (- a 1)))))
  (fermatiter (- n 1)))

(define (fermat-test n a)
  (= (expmod a n n) a))

(define (expmod base exp m)
  (cond ((= exp 0) 1)
        ((even? exp)
         (mod (square (expmod base (/ exp 2) m))
                       m))
        (else
         (mod (* base (expmod base (- exp 1) m))
                       m))))

(define (square n) (* n n))
(define (even? n) (= (mod n 2) 0))

; Interpreter (repl.it) output:
;>>>  (fermat-test-run 561)
;>> #t


;--------------------------------------
; SICP_1.28
; Write the Miller-Rabin test for prime numbers
; Reference used: http://www.billthelizard.com/2010/03/sicp-exercise-128-miller-rabin-test.html

(require (lib "27.ss" "srfi"))

(define (miller-rabin-test n)
  (define (testint a)
    (= (expmod a (- n 1) n) 1))
  (testint (+ 2 (random-integer (- n 2)))))

(define (expmod base exp m)
  (cond ((= exp 0) 1)
        ((even? exp)
          (squarecheck (expmod base (/ exp 2) m) m))
        (else
          (mod (* base (expmod base (- exp 1) m))
               m))))

(define (squarecheck x m)
  (if (and (not (or (= x 1) (= x (- m 1))))
           (= (mod (square x) m) 1))
      0
      (mod (square x) m)))

(define (square n) (* n n))
(define (even? n) (= (mod n 2) 0))



; if squarecheck passes, it feeds its output value into expmod
; if squarecheck fails, it feeds a Zero into expmod, stopping the operation
; My understanding of SICP ex 1.28 is poor

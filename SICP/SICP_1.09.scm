Structure and Interpretation of Computer Programs
Aldashna 1.9

(define (+ a b)
    (if (= a 0) b (inc (+ (dec a ) b ))))

a = 4
b = 5
 
 (+ 4 5)
 (inc (+ (dec 4) 5))
 (inc (+ 3 5))
 (inc (inc (+ (dec 3) 5)))
 (inc (inc (+ 2 5)))
 (inc (inc (inc (+ (dec 2) 5))))
 (inc (inc (inc (+ 1 5))))
 (inc (inc (inc (inc (+ (dec 1) 5)))))
 (inc (inc (inc (inc (+ 0 5)))))
 (inc (inc (inc (inc (5)))))
 (inc (inc (inc (6))))
 (inc (inc (7)))
 (inc (8))
 (9)

; a tip off that this is recursive is that the addition procedure calls itself at the end while nested within an expression.
; this next procedure calls itself, but only as the top expression
    
(define (+ a b)
    (if (= a 0) b (+ (dec a) (inc b))))
    
a = 4
b = 5

(+ 4 5)
(+ (dec 4) (inc 5))
(+ 3 6)
(+ (dec 3) (inc 6))
(+ 2 7)
(+ (dec 2) (inc 7))
(+ 1 8)
(+ (dec 1) (inc 8))
(+ 0 9)
(9)

______________
;   my code for the Fibonacci series [Scheme]:

(define (Fib n)
    (cond ((= n 0) 0)
          ((= n 1) 1)
          (else (+ (Fib (- n 1)) (Fib (- n 2))))))

;
-*- mode: scheme;-*-

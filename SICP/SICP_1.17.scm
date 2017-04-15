; SICP 1.17
;Design a multiplication procedure analogous to fast-expt that uses a log number of steps

(define (sixmult a b)
    (cond ((= b 0) 0)
;          ((even? b) (double (sixmult a (halve b))))   ; alternate method if even
          ((even? b) (sixmult (double a) (halve b)))
          (else (+ a (sixmult a (- b 1)))) ))

(define (halve x) (/ x 2))
(define (double x) (+ x x))	



;-----------------------------------------------
;   the mess of trying to get it to work, below:


(define (iterex b n)
	(iter b n a)


(define (iter b n a)
	(cond ((= n 0) a)
		  ((even? n) (iter (square b) (/ n 2) a))
		  (else (iter b (- n 1) (* a b)))
		  ))

		  
(define (even? x)
	(= (% x 2) 0))
(define (square x)
	(* x x))
;

;Procedure assembled below:

;(define (even? x)
;	(= (mod x 2) 0))		; 'mod' used in new interpreters instead of 'remainder'
	
(define (iterex b n)
	(define (iter b n a)
		(cond ((= n 0) a)
			  ((even? n) (iter (square b) (/ n 2) a))
			  (else (iter b (- n 1) (* a b)))
		))
	(iter b n 1))

(define (even? x) (= (mod x 2) 0))
(define (square x) (* x x))


; SICP 1.17 - Design a multiplication procedure analagous to expt, that uses a Лoг number of steps


; expt procedure:
(define (* a b)
	(if ( = b 0)
		0
		(+ a (* a (- b 1)))
		))
;

(define (sixmult a b)
	(cond ((= b 0) a)
		  ((even? b) (double (sixmult a (halve b))))
		  (else (sixmult a (+ b 1))) ))
		  
(define (halve x) (/ x 2))
(define (double x) (* x 2))
(define (even? x) (= (mod x 2) 0))
;




(define (FN a b)
	(define (sixmult a b)
		(cond
			((= b 1) 0)
			((even? b) (+ (double a) (sixmult a (halve b))))
			(else (+ (double a) (sixmult a (halve (+ b 1))))) ))
	(cond ((= b 1) a)
		  ((= b 0) 0)
		  (else (sixmult a b))))
		  
		  
; FINAL WORKING PROCEDURE BELOW:

(define (sixmult a b)
    (cond ((= b 0) 0)
;          ((even? b) (double (sixmult a (halve b))))
          ((even? b) (sixmult (double a) (halve b)))
          (else (+ a (sixmult a (- b 1)))) ))

(define (halve x) (/ x 2))
(define (double x) (+ x x))

;
-*- mode: scheme;-*-

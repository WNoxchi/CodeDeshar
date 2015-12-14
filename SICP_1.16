; SICP 1.16
; Design a procedure that evolves an iterative exponentiation process that uses successive squaring & uses a log number of steps.


(define (iterex b n)
  (define (iterexacc b n acc)
      (cond ((= n 0) acc)
            ((even? n) (iterexacc (square b) (/ n 2) acc))
            (else (iterexacc b (- n 1) (* acc b)))))
  (iterexacc b n 1.0))
  
  (define (square x) (* x x))
  (define (even? x) (= (mod x 2) 0))


----------------------------
(fast-expt) below:

(define (fast-expt b n)
  (cond ((= n 0) 1)
        ((even? n) (square (fast-expt b (/ n 2))))
        (else (= b (fast-expt b (- n 1))))))
;


; schemewiki:

(define (iterexp b n)
	(define (iter a b n)
		(cond ((= n 0) a)
			  ((even? n) (iter a (square b) (/ n 2)))
			  (else (iter (* a b) b (- n 1)))))
	(iter 1 b n))
(define (square x) (* x x))

; weiqunzhang:

(define (fast-expt b n)
  (define (even? n)
    (= (remainder n 2) 0))
  (define (expt-iter b n a)
    (cond ((= n 0) a)
          ((even? n) (expt-iter (square b) (/ n 2) a))
          (else (expt-iter b (- n 1) (* a b)))))
  (expt-iter b n 1.0))
  
; it's so easy......

---------------------------------------------
; my work solving it below:


;	SICP 1.16	Deisng a proc that evolves an iterative exponentiation process that uses successive squaring & a log # of steps.

Pseudo:

(iterexp base exp)
>>	if exp = 0	=>	return 1
>>	if exp = 1	=>	return base
>>	if exp < 0	=>	Error
>>	if exp > 1	=>	(iter base exp 1 1)

	
;

(define (iter base exp acc count)
	(if (= exp 1) acc
		(iter (base (- exp 1) (* acc base) (+ count 1)))
		))
;

(define (iterexp base exp)
	(cond ((= exp 0) 1)
		  ((= exp 1) base)
		  ((< exp 0) '(Error: input positive integer exponents only))
		  (else (iter base exp 1 1))) )
(define (iter base exp acc count)
	(if (= exp 1) acc
		((- exp 1)(* acc base)(+ count 1)))
;


(define (iter base exp acc count)
	(if (= exp 1)
		acc
		((- exp 1)(* acc base)(+ count 1)) ))
		
;--------------------------------------------------
;	Working recursive mechanism:

(define (iter base exp acc)
    (if (= exp 1)
        (* acc base)
        ( iter base (- exp 1) (* acc base) ) ))
;
---------------------------------------------------

(define (iter base exp acc)
    (if (= exp 1)
        (* acc base)
;        ( iter base (- exp 1) (* acc base) ) ))
        (* acc base)
        
define (*^ exp acc)
            (if (= exp 0)
                acc
                (*^ (exp-1) (* acc base))
                )
;
---------------------------------------------------
working procedure:

(define (^ base exp)
    (define (*^ exp acc)
        (if (= exp 0)
            acc
            (*^ (- exp 1) (* acc base))
            ))
    (*^ exp 1))
	
---------------------------------------------------
; what the fuck:

(define (iterexp base exp)
    (define (iter base exp acc)
    	(if (= exp 1) 
    	    (* acc base)
    		((- exp 1)(* acc base))
    		))
	(cond ((= exp 0) 1)
		  ((= exp 1) base)
		  ((< exp 0) '(Error: input positive integer exponents only))
		  (else (iter base exp 1))) )
	

;
-*- mode: scheme;-*-

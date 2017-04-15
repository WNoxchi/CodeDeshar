; SICP ALDASHNA 1.11
; A function f defined by the rule that:

; f(n) = {	n, if n < 3 }
; f(n) = {	f(n-1) + 2f(n-2) + 3f(n-3), if n >= 3	}

;Define a recursive and iterative procedure that computes f.


;	Recursive:

(define (recur-f n)
	(if (< n 3)
		n
		(+ (recur-f (- n 1)) (* 2(recur-f (- n 2))) (* 3 (recur-f (- n 3))))
		))

;	Iterative:

; We will need 4 state variables:
;	for f(n-1), f(n-2), f(n-3), and a counter - to track what stage of the computation we're in.

; We also need to understand how the variables are changing throughout the procedure.

;	What is the overall state of the function's first recursive call?
;		At f(3) we have: f(3-1) + 2f(3-2) + 3f(3-3) = 2 + 1 + 0 --- & this is at n = 3.

;	Using this as an initial condition (our iterative mechanism wouldn't have been activated otherwise)
;	we have the variables: a = 2, b = 1, c = 0, and counter = 3

;	How this evolves: at n = 4, a now represents a recursive function call. Therefore the new value of a is
;	(a_old) + 2(b) + 3(c) = a_new. b and c change as well. b_new = a_old, and c_new = b_old. The values shift over one variable, with
;	a being a factory for generating each stage's new value. The counter will decrease by 1 at each iteraton.
;	When the counter reaches the (< 3) threshold, the process stops, and the current value of a is returned.

;	This gives the following procedure:

(define (iter a b c count)
	(if (< count 3)
		a
		(iter (+ a (* 2 b) (* 3 c)) a b (- 1 count)) ))
		
;	The above is the internal iteration procedure (or mechanism). We invoke it in the Iterative-function procedure below:
;	(this is also where we specify the initial conditions)

(define (iter-f n)
	(if (< n 3)
		n
		(iter 2 1 0 n)) )

;	The full program is below:

(define (iter-f n)
	(if (< n 3)
		n
		(iter 2 1 0 n)) )
(define (iter a b c count)
	(if (< count 3)
		a
		(iter (+ a (* 2 b) (* 3 c)) a b (- count 1)) ))






;##########################
; some early thinking:
###########################

;Iterative
; f(n) = {	n, if n < 3 }
; f(n) = {	f(n-1) + 2f(n-2) + 3f(n-3), if n >= 3	}

(define (f n)
	(define (iterate a b c count)
		(if (= count 0)
		a
		(iterate b c (+ c (* 2 b) (* 3 a)) (- count 1))))	; the magic is all happening here
	(iterate 0 1 2 n))
	
;Aldashna:

>>>	(f 2)

(iterate 0 1 2 2)	; a=0 b=1 c=2 count=2


>>	count != 0

=>	(iterate b c (+ c (* 2 b) (* 3 a)) (- count 1))
=>	(iterate 1 2 (+ 2 (* 2 1) (* 3 0)) (- 2 1))
=>	(iterate 1 2 (+ 2 2 0) 1)
=>	(iterate 1 2 4 1)	;	a=1 b=2 c=4 count=1

>>	count != 0

=>	(iterate b c (+ c (* 2 b) (* 3 a)) (- count 1))
=>	(iterate 2 4 (+ 4 (* 2 2) (* 3 1)) (- 1 1))
=>	(iterate 2 4 (+ 4 4 3) 0)
=>	(iterate 2 4 11 0)	;	a=2 b=4 c=11 count=0

>>	count = 0

=>	a
=>	2


(define (f n)
	(if (< n 3)
		n
		(iter 0 1 2 n)) )
		
(define (iter a b c count)
	(if (< count 3)
		a
		(iter (+ a (* 2 b) (* 3 c)) a b (- count 1)) ))

;
-*- mode: scheme;-*-

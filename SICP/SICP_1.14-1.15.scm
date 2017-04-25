; SICP 1.14
; Draw the tree illustrating the process generated by the count-change procedure of S.1.2.2 in making change for 11 cents. WHat are orders of growth in space and time as the amount to be changed increases?

Time complexity: T(n,5) = O(n^5)
Space complexity: linear w/ tree depth: O(n)

--------------------------------------------------------------------------
;prelim thoughts typed out:

(define (count-change amount) (cc amount 5))
(define (cc amount kinds-of-coins)
  (cond ((= amount 0) 1)
		((or (< amount 0) (= kinds-of-coins 0)) 0)
		(else (+ (cc amount
					 (- kinds-of-coins 1))
				 (cc (- amount
						(first-denomination
						 kinds-of-coins))
					 kinds-of-coins))) ))
(define (first-denomination kinds-of-coins)
  (cond ((= kinds-of-coins 1) 1)
		((= kinds-of-coins 2) 5)
		((= kinds-of-coins 3) 10)
		((= kinds-of-coins 4) 25)
		((= kinds-of-coins 5) 50)) )

;


(count-change 11)
--> amount = 11
--> (cound-change 11) (cc 11 5)
amount:11 != 0 or < 0 or = kinds-of-coins 0

=> else: (+ (cc amount:11 (- kinds-of-coins 1)) (cc (- amount:11 (first-denomination kinds-of-coins)) kinds-of-coins))

-->		(+ (cc 11 (- 5 1)) (cc (- 11 50) 5) )
-->		(+ (cc 11 (- 4 1)) (cc (- 11 25) 4) (cc (-39) 5))
-->		(+ (cc 11 (- 3 1)) (cc (- 11 10) 3) (cc (- 11 25) 4) (cc (- 11 50) 5))
-->			(+ (cc 11 (2)) (cc (1) 3) (cc (-14) 4) (cc (-39) 5))
-->			(+ (cc 11 (2)) (cc (1) 3) (0) (0))
-->		(+ (cc 11 (- 2 1)) (cc (- 11 5) 2) (+ (cc 1 (- 3 1) (cc (- 1 5) 2)) (0) (0))
-->		(+ (cc 11 (- 2 1)) (cc (- 11 5) 2) (+ (cc 1 (- 3 1) (cc (- 1 5) 2)) (0) (0))

----------------------------------------------------------------------------------
; SICP 1.15
; For the following Sine procedure, how many times is the procedure p applied when (sine 12.15) evaluated? What are orders of growth in space and time, as a function of a, when (sine a) is evaluated?

(define (cube x) (* x x x))
(define (p x) (- (* 3 x) (* 4 (cube x))))
(define (sine angle)
	(if (not (> (abs angle) 0.1))
		angle
		(p (sine (/ angle 3.0)))))
;


(sine angle):
--->	if the absolute value of the angle is NOT greater than 0.1
	--->	return: angle
		otherwise:
			run (p x)
				--> x = (sine (/ angle 3.0))
				=> run:
					(- (* 3 (sine (/ angle 3.0))) (* 4 (cube (sine (/ angle 3.0))) ) ) ; you perform successive divisions
					;	inside: if the sin (angle/3.0) is not < 0.1 : recursive call
;
; All wrong. That's Normal Order above. This is Applicative Order: below:

;	3(0.05) - 4(0.05)^3


(sine angle)
--->	(sine 12.15)
--->	(p (sine 12.15/3.0))
		(p (sine 4.05))
--->	(p (p (sine 4.05/3.0)))
		(p (p (sine 1.35)))
--->	(p (p (p (sine 1.35/3.0))))
		(p (p (p (sine 0.45))))
--->	(p (p (p (p (sine 0.45/3.0)))))
		(p (p (p (p (sine 0.15)))))
--->	(p (p (p (p (p (sine 0.05))))))
		(p (p (p (p (p 0.05)))))
		
		(p (p (p (p 0.1495000))))
		(p (p (p 0.4351345505)))
		(p (p 0.9758465331679))
		(p -0.789563114471)
		-0.3998034574125
;

decreases logarithmically

time complexity defined by:	

log(12.12 / 0.1) / log(3.0)

space complexity:

also log(12.15 / 0.1) / log(3.0)

Growth in complexity in both space and time for (sine a) is: O(log(a))  , or: O(log(n))

A:	n = 5
B: Space & Time: O(log(n))

;
-*- mode: scheme;-*-
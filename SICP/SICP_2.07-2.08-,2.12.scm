;-------------------------------------------------------------------------------
; SICP_2.12 / CS61A
;-------------------------------------------------------------------------------
; It's not clear what it means to divide by an interval spanning zero. Modify
;   Alyssa's code to check for this condition & signal an error if it occurs.
;-------------------------------------------------------------------------------
; Start:  28-Dec-2015 13:40 | Finish: 28-Dec-2015 14:30

(define (makeCenterRange center percent)
  (makeInterval (- center (* center percent))
                (+ center (* center percent))))

(define (percent interval)
  (/ (- (upperBound interval) (center interval))
     (center interval)))

(define (center interval)
  (/ (+ (lowerBound interval) (upperBound interval)) 2))


; easy peasy..

;-------------------------------------------------------------------------------
; SICP_2.10 / CS61A
;-------------------------------------------------------------------------------
; It's not clear what it means to divide by an interval spanning zero. Modify
;   Alyssa's code to check for this condition & signal an error if it occurs.
;-------------------------------------------------------------------------------
; Start:  27-Dec-2015 20:27 | Finish: 27-Dec-2015 20:52

(define (divInterval x y)
  (mulInterval
  x
  (makeInterval (/ 1.0 (upperBound y))
                (/ 1.0 (lowerBound y)))))

;--> Take interval y = (-10, 10)  --- using convention intrvl = (lower, upper)
;   in the division function then:
;   (makeInterval (/ 1.0 (10))
                  (/ 1.0 (-10)))  ->---> (makeInterval (0.1 -0.1)) = (0.1, -0.1)

; So we get it flipped, the lowerbound is greater than the upperbound.
; We can check for this and signal an error.

(define (ZeroSpanCheck Y)
  (and (<= (lowerBound Y) 0)
       (>= (upperBound Y) 0)))

(define (divInterval x y)
  (if (ZeroSpanCheck y)
      (error "Error: Division by Zero-Spanning Interval.")
      (mulInterval
      x
      (makeInterval (/ 1.0 (upperBound y))
                    (/ 1.0 (lowerBound y))))))

; NOTE: [error] undefined in repl.it BIWA Scheme interpreter.

;-------------------------------------------------------------------------------
; SICP_2.08 / CS61A
;-------------------------------------------------------------------------------
; Using reasoning analogous to Alyssa's (addInterval), describe how the
;   difference of 2 intervals can be computed. Define (subInterval).
;-------------------------------------------------------------------------------
; Start:  27-Dec-2015 20:21 | Finish: 27-Dec-2015 20:23

; Subtract the lower bounds of both intervals for the new lower bound, and like-
;   -wise the uppers for the new upper.

(define (subInterval x y)
  (makeInterval (- (lowerBound x) (lowerBound y))
                (- (upperBound x) (upperBound y))))

;-------------------------------------------------------------------------------
; SICP_2.07 / CS61A
;-------------------------------------------------------------------------------
; Alyssa's Interval Arithmetic Program is incomplete. Specify the implementation
;   of the interval abstraction.
;-------------------------------------------------------------------------------
; Start:  27-Dec-2015 20:04 | Finish: 27-Dec-2015 20:19

(define (makeInterval a b) (cons a b))
(define (lowerBound interval) (car interval))
(define (upperBound interval) (cdr interval))

(define (addInterval x y)
  (makeInterval (+ (lowerBound x) (lowerBound y))
                (+ (upperBound x) (upperBound y))))

(define (mulInterval x y)
  (let ((p1 (* (lowerBound x) (lowerBound y)))
        (p2 (* (lowerBound x) (upperBound y)))
        (p3 (* (upperBound x) (lowerBound y)))
        (p4 (* (upperBound x) (upperBound y))))
  (makeInterval (min p1 p2 p3 p4)
                (max p1 p2 p3 p4))))

(define (divInterval x y)
  (mulInterval
  x
  (makeInterval (/ 1.0 (upperBound y))
                (/ 1.0 (lowerBound y)))))

;-------------------------------------------------------------------------------
; Definition of interval abstraction:

(define (makeInterval a b) (cons a b))

;--> idea:  2 intervals can be added by summing their lower bounds and their
;   upper bounds to get minimum and maximum sum.

(define (addInterval x y)
  (makeInterval (+ (lowerBound x) (lowerBound y))
                (+ (upperBound x) (upperBound y))))

;-->  idea: product of 2 intervals got by finding min and max of products of
;   bounds, & using them as bounds of resulting interval.

(define (mulInterval x y)
  (let ((p1 (* (lowerBound x) (lowerBound y)))
        (p2 (* (lowerBound x) (upperBound y)))
        (p3 (* (upperBound x) (lowerBound y)))
        (p4 (* (upperBound x) (upperBound y))))
  (makeInterval (min p1 p2 p3 p4)
                (max p1 p2 p3 p4))))
;
;-->  idea: divide 2 intervals, multip 1st by reciprocal of 2nd: x/y = x * y^-1

(define (divInterval x y)
  (mulInterval
  x
  (makeInterval (/ 1.0 (upperBound y))
                (/ 1.0 (lowerBound y)))))

;-------------------
(define (lowerBound interval) (car interval))
(define (upperBound interval) (cdr interval))

;-*- mode:scheme;-*-
; Checked against:  http://www.billthelizard.com/2010/12/sicp-27-211-extended-exercise-interval.html
; Had to rewrite after Atom crashing

;----------------------
; old version found:

; SICP_2.09 / CS61A
;-------------------------------------------------------------------------------
; It is not clear what's meant by dividing by an interval that spans zero.
; Modify Alyssa's code to check for this condition & signal an error if it does.
;-------------------------------------------------------------------------------
; Start:  27-Dec-2015 19:47




; SICP_2.08 / CS61A
;-------------------------------------------------------------------------------
; Using reasoning similar to Alyssa's (addInterval), describe how the difference
;   of 2 intervals can be computed. Define (subInterval).
;-------------------------------------------------------------------------------
; Start:  27-Dec-2015 19:41 | Finish: 27-Dec-2015 19:43

; >>> Subtract the lower bounds of both intervals, and subtract the upper bounds
;   of both intervals, and construct a new interval from the resulting bounds.

(define (subInterval x y)
  (makeInterval (- (lowerBound x) (lowerBound y))
                (- (upperBound x) (upperBound y))))

; SICP_2.07 / CS61A
;-------------------------------------------------------------------------------
; Complete the Interval Arithmatic Program by specifying the implementation of
;   the interval abstraction.
;-------------------------------------------------------------------------------
; Start:  27-Dec-2015 19:08 | Finish: 27-Dec-2015 19:38

(define (makeInterval a b) (cons a b))
(define (lowerBound interval) (car interval))
(define (upperBound interval) (cdr interval))

(define (addInterval x y)
  (makeInterval (+ (lowerBound x) (lowerBound y))
                (+ (upperBound x) (upperBound y))))

(define (mulInterval x y)
  (let ((p1 (* (lowerBound x) (lowerBound y)))
        (p2 (* (lowerBound x) (upperBound y)))
        (p3 (* (upperBound x) (lowerBound y)))
        (p4 (* (upperBound x) (upperBound y))))
  (makeInterval (min p1 p2 p3 p4)
                (max p1 p2 p3 p4))))

(define (divInterval x y)
  (mulInterval
    x
    (makeInterval (/ 1.0 (upperBound y))
                  (/ 1.0 (lowerBound y)))))

;-------------------------------------------------------------------------------
; Definition of interval constructor:

(define (makeInterval a b) (cons a b))

; >> Define selectors upperBound and lowerBound to complete the implementation.

(define (lowerBound interval) car interval)
(define (upperBound interval) cdr interval)


;-->  idea: min value of an interval is sum of lower bounds, max value is sum of
;-->    upper bounds.
;-------------------
(define (addInterval x y)
  (makeInterval (+ (lowerBound x) (lowerBound y))
                (+ (upperBOund x) (upperBound y))))
;-------------------
;-->  idea: product of 2 intervals = min & max of the products of the bounds, &
;-->    using them as bounds of resulting interval.
;-------------------
(define (mulInterval x y)
  (let ((p1 (* (lowerBound x) (lowerBound y)))
        (p2 (* (lowerBound x) (upperBound y)))
        (p3 (* (upperBound x) (lowerBound y)))
        (p4 (* (upperBound x) (upperBound y))))
  (makeInterval (min p1 p2 p3 p4)
                (max p1 p2 p3 p4))))
;-------------------
;-->  idea: divide 2 intervals: multip 1st by reciprocal of 2nd: x/y = x * y^-1
;-->  NOTE: bounds of reciprocal interval are reciprocal of upper bound & lower,
;-->    in that order.
;-------------------
(define (divInterval x y)
  (mulInterval
    x
    (makeInterval (/ 1.0 (upperBound y))
                  (/ 1.0 (lowerBound y)))))

;-*- mode:scheme;-*-
; Checked against:  http://www.billthelizard.com/2010/12/sicp-27-211-extended-exercise-interval.html

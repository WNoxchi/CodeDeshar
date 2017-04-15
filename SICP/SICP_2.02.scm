; SICP_2.02
;-------------------------------------------------------------------------------
; Define a constructor <makesegment> and selectors <startsegment> & <endsegment>
;   that def the representation of line segments in terms of points.
; Point reprsnt as pair of numbers: x, y. Specify constructor <makepoint> and
;   selectors <xpoint> & <ypoint> that def this.
; Finally, def proc <midpointsegment> that takes a line segment as argument and
;   returns its midpoint.
;-------------------------------------------------------------------------------
; Start:  24-Dec-2015 14:07   |   STOP: 24-Dec-2015 16:06   |   Completed: 24-Dec-2015 19:11

(define (printpoint point)
  (newline)
  (display "(")
  (display (xpoint point))
  (display ",")
  (display (ypoint point))
  (display ")"))

(define (makpoint x y) (cons x y))

(define (xpoint point) (car point))
(define (ypoint point) (cdr point))

(define (makseg start end) (cons start end))

(define (startseg seg) (car seg))
(define (endseg seg) (cdr seg))

(define (midpoint segment)
  (cons (/ (+ (xpoint (startseg (seg))) (xpoint (endseg (seg)))) 2)
        (/ (+ (ypoint (startseg (seg))) (ypoint (endseg (seg)))) 2)))

; USAGE:

> (define a (make-point -1 2))
> (define b (make-point 3 -6))
> (define s (make-segment a b))
> (define m (midpoint-segment s))
> (print-point m)

; try to understand this the best I can
;-------------------------------------------------------------------------------


(midpointseg x1 y1 x2 y2) ==> returns midpoint
  (

Distance = sqrt( (x2 - x1)^2 + (y2 - y1)^2 ) --- d = distance between points
Midpoint = (x1 + x2)/2 , (y2 - y1)/2


<midpoitseg> takes <makeseg> and returns midpoint of it.
<makeseg> takes 2 <makepoint>s and constructs a segment.
<makepoint> takes <xpoint> and <ypoint> and constructs a point.

; to print points:

(define (printpoint point)
  (newline)
  (display "(")
  (display (xpoint point))
  (display ",")
  (display (ypoint point))
  (display ")"))

; TEST:
;-------------------------------------------------------------------------------

(define (midpoint x1 x2 y1 y2)
  (define (START point)
    (cons x1 y1))
  (define (END point)
    (cons x2 y2))
  (cons (/ (- (car END) (car START)) 2)
        (/ (- (cdr END) (cdr START)) 2)))

        ; ---> issue here: how will END & START know which args to take?
        ; -->> that's why I need another selector to deal with that layer
        ; --> So: define midpoint as taking in points, not coordinates
;
;-----------------------------------------
(define (makrat n d) (printrat(cons n d)))
(define (numer x) (car x))
(define (denom x) (cdr x))
;-----------------------------------------


(define (midpoint START END)
  (define START (cons x y))
  (define END (cons x y))
  (cons (/ (- (car END) (car START)) 2)
        (/ (- (cdr END) (cdr START)) 2)))

;-----------------------------------------------------------
; trying to figure things out from: http://www.billthelizard.com/2010/09/sicp-22-line-segments-in-plane.html



we need to define a constructor and selectors for creating line segments in a plane

A line segment is represented by a starting point and an ending point.

We also need to create a constructor and selectors for creating points in a plane.
    --->  where a point is represented by an x and y value.

Finally, using these constructors and selectors we need to define a <midpointseg> proc
  that takes a line segment as its arg and returns the midpoint of that segment.

(define (printpoint point)
  (newline)
  (display "(")
  (display (xpoint point))
  (display ",")
  (display (ypoint point))
  (display ")"))

;-----------------------------
; Defining points in a plane:

; point constructor
(define (makepoint x y) (cons x y))

; point selectors
(define (xpoint point) (car point))
(define (ypoint point) (cdr point))

;-----------------------------
; Defining segments:

; segment constructor
(define (makeseg start end) (cons start end))

; segment selectors:
(define (startseg segment) (car segment))
(define (endseg segment) (cdr segment))


;-----------------------------
; proc takes a segment and returns a point:

(define (midpointseg segment)
  (makepoint (/ (+ (xpoint (startseg segment))
                  (xpoint (endseg segment)))
                2)
             (/ (+ (ypoint (startseg segment))
                  (ypoint (endseg segment)))
                2)))
;
usage:
;> (define a (make-point 6.4 3))
;> (define b (make-point -10.7 4))
;> (define s (make-segment a b))
;> (define m (midpoint-segment s))
;> (print-point m)

;-*-mode:scheme;-*-

;-------------------------------------------------------------------------------
;   SICP/CS61A  Homework 2  |   11-Jan-2016 12:27   |   11-Jan-2016 13:09
;-------------------------------------------------------------------------------
;   HW Soln: https://github.com/fgalassi/cs61a-sp11/tree/master/homework
;   HW Handout: http://wla.berkeley.edu/~cs61a/reader/nodate-hw.pdf


;S:  11-Jan-2016 12:27  F:  11-Jan-2016 12:34
;;-------------------------------------------
;2.  Generalize the pattern in (squares) and (pigl-sent) to create a higher-order
;    proc called (every) that applies an arbitrary proc, given as an arg, to each
;    word of an arg sentence.
;
;Ald:    >   (every square '(1 2 3 4))
;        (1 4 9 16)
;        >   (every first '(nowhere man))
;        (n m)

(define (every proc sent)
    (if (empty? sent)
        '()
        (se (proc (first sent))
            (every proc (bf sent))) ))

;squares:
;(define (squares nums)
;    (if (empty? nums)
;        '()
;        (se (square (first nums))
;            (squares (bf nums)) )))


;-------------------------------------------
;3.  Define the recursive proc (fact) using (lambda)
;From:   https://github.com/fgalassi/cs61a-sp11/blob/master/homework/h2.extra.scm

(
    (lambda (fact)  ;   using a lambda call to pass proc (fact) as arg into what I assume is another lambda call
        (fact 5 fact)
    )
    (lambda (n self)
        (if (= n 0)
            1
            (* n (self (- n 1) self))
        )
    )
)

; I see what he's doing. The first lambda call defines a procedure (fact) as being
;     itself taking arguments 5 and itself.
; The second lambda call defines what those arguments (5 &-itself) are:
;    5 is n, itself(fact) is self. This is where the factorial recursion comes in:
;    if n is equal to 0, return 1. otherwise: multiply n with (self (n-1) self),
;    which follows the form of (fact 5 fact). In this way, the process recurses,
;    reducing n by 1 at each step until n = 0, in which case it returns 1, and then
;    multiplies all the n's resulting from each step of the process: 5*4*3*2*1.
;
;He is using C/Java/Python styling and the Lisp/Scheme equivalent would be:

((lambda (fact) (fact 5 fact))
 (lambda (n self)
     (if (= n 0)
         1
         (* n (self (- n 1) self))) ))

;I need to learn how to generate this, thinking. I can look at it and deconstruct it,
;that's the first step. It's actually very simple. Because it's recursive, one lambda
;call specifies the recursion from a high-level (or higher-order?) and another lambda
;call specifies the internal recursive mechanism. The second L call is fed into the
;first.
;
;Notice: in the first Lambda: the proc (fact) is defined as (<proc> <arg> <arg>)
;so the procedure factorial takes as arguments 5 and the procedure factorial as
;arguments.


;-*- mode:scheme;-*-

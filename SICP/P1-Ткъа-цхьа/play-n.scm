;-------------------------------------------------------------------------------
;   SICP / CS61A    |   Project 1: Ткъацхьа/Tq̇acẋa    |   play-n.scm
;-------------------------------------------------------------------------------
;   Start:  07-Jan-2016 22:27   |   Finish: 07-Jan-2016 22:40
;-------------------------------------------------------------------------------
;   http://wla.berkeley.edu/~cs61a/reader/nodate-21.pdf
;   Write a proc play-n s.t. (play-n strategy n) plays n games w a given strat
;       & returns the number of games the customer won minus lost.

(load "twenty-one")

(define (play-n strategy n)
    (if (= n 1) (twenty-one strategy)
                (+ (twenty-one strategy) (play-n strategy (- n 1))) ))
; I don't know how to tell if won or lost....
; Unless I'm wrong looks like: 1 =  win, 0 = tie, -1 = loss.
; If so, then the hard part's done for me. yey

;   Holy shit I got it right. Only difference is, I could just have n = 0 as
;   terminal condition and return 0. I didn't know that, so I just had a final
;   proc call at n = 1. But the n = 0 way would prevent a bug so it'd be better.

;   Below is from: https://github.com/fgalassi/cs61a-sp11/blob/master/projects/blackjack/normal/play-n.scm

;(load "twenty-one")
;
;(define (play-n strategy n)
;  (if (= n 0)
;    0
;    (+ (twenty-one strategy) (play-n strategy (- n 1)))))

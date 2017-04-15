;-------------------------------------------------------------------------------
;   SICP / CS61A    |   Project 1: Ткъацхьа/Tq̇acẋa    |   stop-at.scm
;-------------------------------------------------------------------------------
;   Start:  08-Jan-2016 19:00   |   Finish: 08-Jan-2016 19:10
;-------------------------------------------------------------------------------
;   http://wla.berkeley.edu/~cs61a/reader/nodate-21.pdf
;>>>Generalize stop-at-17.scm by defining (stop-at n) ->should return a strategy
;   that keeps hitting until a hand's total is n or more.
;   Aldashna: (stop-at 17) is equivalent to (stop-at-17)

(load "best-total")

(define (stop-at n)
    (< (best-total hand) n))

; so return #t/#f: (best-total hand) < n

;----------------------------------------
; Checked against:  https://github.com/fgalassi/cs61a-sp11/blob/master/projects/blackjack/normal/stop-at.scm

;(load "best-total")

;(define (stop-at n)
;  (lambda (hand dealer-card)
;    (< (best-total hand) n)))

;----------------------------------------

; So if I'm getting this right, the issue with my code is that you need a way to
;   enter in <hand> and <dealer-card> as arguments to be fed into (best-total)
;   and checked against <n>.
; So that's why he uses a lambda to internally define the mechanics of the stop-at
;   procedure. hmmmm..

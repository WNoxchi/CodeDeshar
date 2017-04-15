;-------------------------------------------------------------------------------
;   SICP / CS61A    |   Project 1: BlackJack    |   stop-at-17.scm
;-------------------------------------------
;   Start:  07-Jan-2016 18:42   |   07-Jan-2016 18:47
;-------------------------------------------------------------------------------
;   Define a strategy proc (stop-at-17) that's identical to the dealers,
;   i.e. takes a card IFF total so far is less than 17

;   ORIGINAL ATTEMPT:
(define (stop-at-17 card)
    (if (< total 17) (<<add card to total>>)
                     '()))

; Answer: https://github.com/fgalassi/cs61a-sp11/blob/master/projects/blackjack/normal/stop-at-17.scm

(load "best-total")
;   aha, so you can just import other procs this way... makes sense.... shit you can.. okay.
(define (stop-at-17 hand dealer-card)
    (< (best-total hand) 17))
;   I don't know what <dealer-card> is really doing here.

;-------------------------------------------------------------------------------
;   SICP / CS61A    |   Project 1: Ткъацхьа/Tq̇acẋa - 9    |   reckless.scm
;-------------------------------------------------------------------------------
;   Start:  09-Jan-2016 15:46   |   Fin:    09-Jan-2016 15:57
;-------------------------------------------------------------------------------
;   http://wla.berkeley.edu/~cs61a/reader/nodate-21.pdf
;>>>Define a proc (reckless) that takes a strategy as arg and returns another
;   strategy. This new strat should take one more card than the original would.
;   IOW: new strat should stand if the old strat would stand on butlast of
;   customer's hand.

(load "best-total")

(define (reckless strategy)
    (lambda (hand dealer-card)
        (strategy (butlast hand) dealer-card)))
;----------------------------------------
;   Checking against:   https://github.com/fgalassi/cs61a-sp11/blob/master/projects/blackjack/normal/reckless.scm

(define (reckless strategy)
  (define (hit? hand dealer-card) (strategy hand dealer-card))
  (define (previous-hit? hand dealer-card)
    (and
      (not (empty? hand))
      (strategy (butlast hand) dealer-card)))
  (lambda (hand dealer-card) (or (hit? hand dealer-card) (previous-hit? hand dealer-card))))

;----------------------------------------

;Okay I see what he's doing here. define a HIT inputing <hand> <dealer-card> as the proc
;(strategy <hand> <dealer-card>).
;Then define previous-hit?, inputing <hand> & <dealer-card> as:
;    returning True IFF BOTH are True:
;            hand is not empty
;            strategy on <butlast hand> & <dealer-card> would return true.
;Finally: using Lambda to pass in <hand> & <dealer-card> as args to the following procs (hit?) & (previous-hit?):
;    return True if EITHER of the following return True:
;        (hit?) on <hand> & <dealer-card> ------ (previous-hit?) on <hand> & <dealer-card>

; Right so there's that.

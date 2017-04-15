;-------------------------------------------------------------------------------
;   SICP / CS61A    |   Project 1: Ткъацхьа/Tq̇acẋa - 7    |   suit-strategy.scm
;-------------------------------------------------------------------------------
;   Start:  09-Jan-2016 13:29   |   Finish: 09-Jan-2016 14:33
;-------------------------------------------------------------------------------
;   http://wla.berkeley.edu/~cs61a/reader/nodate-21.pdf
;>>>Generalize valentine.scm by defining a (suit-strategy) that takes 3 args:
;   a suit (h, s, d, or c); a strategy to be used if your hand doesn't include
;   that suit; and a strategy to be used if you hand does include that suit.
;   Show how you could use this function and the (stop-at) function to redefine
;   (valentine) strat.

;(suit-strategy <suit> <alt-strategy> <strategy>)

; ahaa, so maybe <hand> and <card> from 1.6 were implicit then. That makes sense.
;   (looking at <alt-strat> and <strat> above)

(define (suit-strategy suit alt-strategy strategy)
;   if any? of hand equal? to <suit>  ==>> strategy
;   else: alt-strategy
    (if (has-suit? suit hand) strategy alt-strategy))

(define (has-suit? suit hand)
    (any? (lambda (card) (suit? suit card)) hand))
; shit... hinca so kxeta.. the way this lambda proc works (structure from answer of 1.6)
; is:   return boolean of (any? <lambda> <hand>) --- <lambda> defined internally as:
;       argument: <card>, procedure: run (suit?) on <card>
;   Finally: check if the result of lambda: (suit? card), matches anything in <hand>
; oy so simple. well good I understand now.  EDIT: added arg <suit> to check <card> against.
(define (suit? suit card)
    (equal? suit (last card)))
; My full procedure below:---------------
(load "best-total")

(define (suit-strategy suit alt-strategy strategy)
    (if (has-suit? hand) strategy alt-strategy))

(define (has-suit? suit hand)
    (any? (lambda (card) (suit? suit card)) hand))

(define (suit? suit card)
    (equal? suit (last card)))
;----------------------------------------
;Now Checking against: https://github.com/fgalassi/cs61a-sp11/blob/master/projects/blackjack/normal/suit-strategy.scm

(load "higher-order")

(define (suit-strategy suit has-suit-strategy hasnt-suit-strategy)
  (lambda (hand dealer-card)                    ;   okay he specifies a way to check the dealer's card, I don't check, I take as arg. I should change that.
    (if (suit-in-hand? suit hand)
      (has-suit-strategy hand dealer-card)      ;   okay looks like I was close. the logic is the same, but he has one layer on top,
      (hasnt-suit-strategy hand dealer-card)))) ;    that turns the output of (<hand> <dealer-card>), the dealer's
                            ; holy fuck now I understand. My mistake is I return a strategy, which is a procedure..
(define (suit? suit)        ;  but with no arguments! The strat I return has to be actionable ==> return strategy with my hand & dealer's card as args. okay.
  (lambda (card) (equal? (last card) suit)))

(define (suit-in-hand? suit hand)
  (any? (suit? suit) hand))

;----------------------------------------
;   NOTES:  λ is needed because <hand> and <dealer-card> needed to be inputted as arguments into either of
;           the procs resulting from the <if>. Could define a further proc but faster this way.
;   I'll retry this problem later.

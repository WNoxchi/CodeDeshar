;-------------------------------------------------------------------------------
;   SICP / CS61A    |   Project 1: Ткъацхьа/Tq̇acẋa    |   play-n.scm
;-------------------------------------------------------------------------------
;   Start:  08-Jan-2016 18:28   |   Finish: 08-Jan-2016 18:54
;-------------------------------------------------------------------------------
;   http://wla.berkeley.edu/~cs61a/reader/nodate-21.pdf
;>>>Define a strategy named dealer-sensitive that "hits" (takes a card) IFF the
;   dealer has an ace, 7, 8, 9, 10, or picture card showing, and the customer
;   has < 17, or the dealer has 2,3,4,5, or 6 showing & customer has < 12.

(load "best-total")

(define (dealer-sensitive hand dealer-card)
    (cond ((< hand 17)
           (member? (card-value dealer-card) '(a j q k 7 8 9 10) ))
          ((< hand 12) 
           (member? (card-value dealer-card) '(a 7 8 9 10) )) ))  ; idk if I should structure this differently
; I kind of feel like this should work, but I'm not sure about checking the dealer's card.
; It does return a #t/#f so..

; Two logic branches:

; Customer has < 17:
;   HIT IFF dealer has ace,7,8,9,10,picture

; Customer has < 12:
;   HIT IFF dealer has 2,3,4,5,6

;----------------------------------------
;   Checking from:  https://github.com/fgalassi/cs61a-sp11/blob/master/projects/blackjack/normal/dealer-sensitive.scm

;(load "best-total")
;
;(define (dealer-sensitive hand dealer-card)
;  (let ((player-points (best-total hand))
;        (dealer-points (card-points dealer-card)))
;    (or
;      (and (> dealer-points 6) (< player-points 17))
;      (and (<= dealer-points 6) (< player-points 12)))))

;----------------------------------------

;   So it looks like he uses <let> to internally define player-points,
;   THEN he uses OR to return #t if either case is true. I like this.
;   Also it's logically implicit what cards the dealer has if he has less or more than 6 points.
;   When/if I redo this project I'm going to try and write it this way.

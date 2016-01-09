;-------------------------------------------------------------------------------
;   SICP / CS61A    |   Project 1: Ткъацхьа/Tq̇acẋa    |   valentine.scm
;-------------------------------------------------------------------------------
;   Start:  08-Jan-2016 19:13   |   Fin:    09-Jan-2016
;-------------------------------------------------------------------------------
;   http://wla.berkeley.edu/~cs61a/reader/nodate-21.pdf
;>>>Define a <valentine> strategy that stops at 17, unless you have a heart in
;   your hand, in which case it stops at 19.

(load "best-total")

(define (valentine hand)
    (lambda (hand dealer-card)
        (if (equal? hand ;;;;;;;
; so how do I tell if a heart is in the hand? oh, (equal? (last card) 'h)
; now how do I look through each card in a hand?
;   should I iterate through a sentence/list of a hand until i get to the end?
;   is that totally retarded? ... Stanford's CS106A has nothing on Berkeley's old SICP/CS61A

(load "best-total")

(define (valentine hand)
    (define (has-heart? hand)
        (cond ((equal? (last (first hand)) 'h) #t)
              ((not (equal? (last (first hand)) 'h) #t)
                    (has-heart? (bf hand)))
              (else #f)))
    (lambda (hand dealer-card)
        (if (has-heart? hand) (< (best-total hand) 19)
                              (< (best-total hand) 17)) ))

;----------------------------------------
; Checking against:

(load "best-total")

;(define (valentine-strategy hand dealer-card)
;  (let ((player-points (best-total hand)))
;    (or
;      (and (has-hearts? hand) (< player-points 19))
;      (< player-points 17))))
;(define (valentine-strategy hand dealer-card)
;    (let ((player-points (best-total hand)))
;      (or
;        (and (has-hearts? hand dealer-card)
;             (< player-points 17))) ))
;--------------------------
 (define (has-hearts? hand)
    (any? (lambda (card) (heart? card)) hand))
; so has hearts returns true or false if any card is a heart
(define (heart? card)
    (equal? (last card) 'h))
; use equal? when checking individual elements of an item against something else,
; use any? when checking if any members are part of a

(define (has-hearts? hand)
  (any? (lambda (card) (heart? card)) hand))
; apply hand as the argument card to heart?
; looks like I'm having some fundamental misunderstanding of how the arguemnts
;    <hand> and <card> work. if they're just kinda implicit.

(define (heart? card)
  (equal? (last card) 'h))

;----------------------------------------
;   So he's using a let.
; ah okay, so the way let works is:
(let ((a exp1)
      (b exp2))
  exp)
;--->equivalent to:
((lambda (a b)
    exp)
 exp1 exp2)
 ; from: http://stackoverflow.com/questions/946050/using-let-in-scheme
;   I need to take time to learn exactly how <let> works. Becuase I kind of see
;   what he's doing, but I'm not exactly sure.
;   Also I never knew of the <any?> predicate before.

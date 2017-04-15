;-------------------------------------------------------------------------------
;   SICP / CS61A    |   Project 1: BlackJack    |   best-total.scm
;-------------------------------------------
;   Start:  07-Jan-2016 17:24   |   07-Jan-2016 18:39
;-------------------------------------------------------------------------------

;   ORIGINAL ATTEMPT:
;(define (best-total sent)
;    (define (handler sent)
;        (cond ((equals? (first (first sent)) 'j) 10)
;              ((equals? (first (first sent)) 'q) 10)
;              ((equals? (first (first sent)) 'k) 10)
;              ((equals? (first (first sent)) 'a) 11)
;              (else (first (first sent)))) )
;    (if (equals? (bf sent) '())
;        (handler sent)
;        (+ (handler (first (first sent))) (best-total (bf sent))) ) )

;   Answer from: https://github.com/fgalassi/cs61a-sp11/blob/master/projects/blackjack/normal/best-total.scm

(load "higher-order")
;   I never dealt with loading before but okey doke.

(define (best-total hand)
    (let ((total-non-aces (sum (map card-points (non-aces hand)))))
        (add-n-aces-to (count (aces hand)) total-non-aces)) )

; I need to relearn what <let> and <map> do exactly

(define (valid-total? total)
    (<= total 21))

(define (card-points card)
    (cond ((face-card? card) 10)
          ((ace? card) 11)
          (else (card-value card))))
; if card is facecard: 10 -- if ace: 11 -- otherwise just take its value

(define (add-n-aces-to number-of-aces total)
    (let ((highest-total (+ total (* number-of-aces 11))))
        (if (or (valid-total? highest-total) (= 0 number-of-aces))
            highest-total
            (add-n-aces-to (- number-of-aces 1) (+ total 1))) ))
; this makes sense, I have to go through this again

(define (non-aces cards)
    (filter (compose not ace?) cards))
; so if it's true (that the card isn't an ace) then, yeah....ya?

(define (aces cards)
    (filter ace? cards))
; oh cool, I think I sorta get how this filter thing works

(define (ace? card)
    (equal? (card-value card) 'a))

(define (face-card? card)
    (member? (card-value card) '(j q k)))

; oh shit that's how you use <member?>, okay.
; then a definition for <card-value>:

(define (card-value card)
    (butlast card))
; perfect sense, take everything but the last letter (suit) of the card.

;   RECURSIVE:
;(define (best-total hand)
;    (bt hand 0))
;
;(define (bt hand total)
;    (cond ((not (valid-total? total)) 0)
;          ((empty? hand) total)
;          (else (let ((card (first hand))
;                      (rest (butfirst hand)))   ;   I have no idea what's going on in this <let>
;                  (if (ace? card)
;                    (max (bt rest (+ total 1)) (by rest (+ total 11)))
;                    (bt rest (+ total (card-points card)))) )) ))

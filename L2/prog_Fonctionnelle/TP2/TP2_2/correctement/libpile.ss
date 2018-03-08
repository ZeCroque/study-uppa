; libpile.ss
; Programmation fonctionnelle TP2 , programmation d'une calculette
; (c) Eric Gouardères, Mars 2017

(define m '())

(define (vide?)
  (null? m))

(define (vider)
  (set! m '()))

(define (empiler x)
  (set! m (cons x m)))

(define (depiler)
  (if (vide?)
      (begin
        (display "erreur pile vide")
        'err_vide)
        (set! m (cdr m))))
  
(define (sommet)
  (if (vide?)
      (begin
        (display "erreur pile vide")
        'err_vide)
      (car m)))
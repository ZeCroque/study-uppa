(define valeur '(2 3 4 5 6 7 8 9 10 valet dame roi as))
(define couleur '(pique coeur carreau trefle))
(define main '((roi . pique)(dame . pique)(10 . pique)(6 . pique)(4 . pique)(dame . coeur)(10 . coeur)(8 . coeur)(valet . treffle)(6 . treffle)(as . carreau)(valet . carreau)))
(define exemple '(roi . carreau))

(define (getValeur c)
 (car c) 
)

(define (getCouleur c)
 (cdr c) 
)

(define(appartient? k l)
 (cond
  ((null? l) #f)
  ((equal? k (car l)) #t)
  (else (appartient? k (cdr l)))
 )
)

(define (carte? c)
  (and(appartient? (getCouleur c) couleur) (appartient? (getValeur c) valeur)))


(define (points c)
  (if (null? c)
     -1
     (cond
       ((equal? (car c) 'as)4)
       ((equal? (car c) 'roi)3)
       ((equal? (car c) 'dame)2)
       ((equal? (car c) 'valet)1)
       (else 0)
     )
  )
)

(define (evalue main)
  (if (null? main)
      0
      (+(points (car main))(evalue (cdr main))) 
  )
)

(getCouleur exemple)
(getValeur exemple)
(carte? exemple)
(points exemple)
(evalue main)

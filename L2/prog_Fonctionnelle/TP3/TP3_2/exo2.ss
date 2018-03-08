(define population '((homme 20) (femme 35) (homme 40) (femme 15) (homme 50)))

(define (compte sexe pop)
  (if (null? pop)
      0
      (if (equal? (car(car pop)) sexe)
          (+ 1 (compte sexe (cdr pop)))
          (+ 0 (compte sexe (cdr pop)))
       )
   )
)

(compte 'femme population)

(define (moyenne
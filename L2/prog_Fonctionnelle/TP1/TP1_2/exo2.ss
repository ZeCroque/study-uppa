(define (emballer-100 n) (begin
                           (newline)
                           (display (quotient n 100))
                           (display " boite(s) de 100 remplie(s)" )
                           (newline)
                           (remainder n 100)))

(define (emballer-50 n) (begin
                           (newline)
                           (display (quotient n 50))
                           (display " boite(s) de 50 remplie(s)" )
                           (newline)
                           (remainder n 50)))

(define (emballer-10 n) (begin
                           (newline)
                           (display (quotient n 10))
                           (display " boite(s) de 10 remplie(s)" )
                           (newline)
                           (remainder n 10)))

(define (emballer-tout n) (begin
                                 (emballer-10(emballer-50 (emballer-100 n)))
                                 (display "Emballage terminé")))


(emballer-tout 550)
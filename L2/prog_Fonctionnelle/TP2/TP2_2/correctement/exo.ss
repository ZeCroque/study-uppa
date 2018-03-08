(load "libpile.ss")
(define binaire '(+ - / *))
(define unaire '(abs sqrt cos sin))

(define (appartient? li elt)
       (cond
         ((null? li) #f)
         ((equal? (car li) elt) #t)
         (else (appartient? (cdr li) elt))
        ))
  

(define (calcpost)
  (let ((op (read))
        (tmp 0)
        (tmp1 0))
  (if (equal? op 'fin)
      (display "Fin!")
      (begin
        (cond 
          ((number? op)(empiler op))
         ((appartient? binaire op)(begin 
                                     (set! tmp (sommet))
                                     (depiler)
                                     (set! tmp1 (sommet))
                                     (depiler)
                                     (empiler ((eval op (interaction-environment))tmp1 tmp))
                                    
                                     ))
          ((appartient? unaire op)(begin
                                    (set! tmp (sommet))
                                    (depiler)
                                    (empiler ((eval op (interaction-environment)) tmp))
                                    ))
         ((equal? '= op)  (begin 
                            (display (sommet)) 
                            (newline))))  

        (calcpost)))))

(calcpost)
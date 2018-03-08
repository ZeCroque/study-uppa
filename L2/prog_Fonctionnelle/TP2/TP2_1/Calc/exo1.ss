(load "grafcalc.ss")
(load "libcalc.ss")

(define (add a b)
        (if(non_zero? b)
           (add (incrementer a) (decrementer b))
           a))

(define (sou a b)
        (if(non_zero? b)
           (sou (decrementer a) (decrementer b))
           a))

(define (domul a b aprime)
        (if(non_zero? b)
           (domul (add a aprime) (decrementer b) aprime)
           a))

(define (mul a b)
        (domul 0 b a))

(define (dodiv a b q)
        (if(sup_egal? (sou a b) 0)
           (dodiv (sou a b) b (incrementer q))
           q))

(define (div a b)
        (dodiv a b 0))
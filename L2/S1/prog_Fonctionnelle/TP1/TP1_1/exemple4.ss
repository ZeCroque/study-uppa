(define(m->s x)(* 60 x))
(define(h->m x)(* 60 x))
(define(h->s x)(m->s (h->m x)))
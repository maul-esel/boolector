(set-logic QF_BV)
(declare-fun u0 () (_ BitVec 8))
(declare-fun u1 () (_ BitVec 8))
(declare-fun u2 () (_ BitVec 8))
(assert (= (bvadd (bvshl u0 (bvshl (_ bv1 8) (_ bv0 8))) u0) (bvnot (_ bv0 8))))
(assert (= (bvadd (bvshl u1 (bvshl (_ bv1 8) (_ bv1 8))) u1) (bvnot (_ bv0 8))))
(assert (= (bvadd (bvshl u2 (bvshl (_ bv1 8) (_ bv2 8))) u2) (bvnot (_ bv0 8))))
(declare-fun b0 () (_ BitVec 8))
(declare-fun b1 () (_ BitVec 8))
(declare-fun b2 () (_ BitVec 8))
(assert (= (bvxor (bvnot (_ bv0 8)) b0) (bvshl b0 (_ bv1 8))))
(assert (= (bvxor b0 b1) (bvshl b1 (_ bv1 8))))
(assert (= (bvxor (bvand b0 b1) b2) (bvshl b2 (_ bv1 8))))
(assert (not (and (= b0 u0) (= b1 u1) (= b2 u2))))

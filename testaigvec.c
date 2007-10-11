#include "testaigvec.h"
#include "btoraigvec.h"
#include "btormem.h"
#include "testrunner.h"

#ifdef NDEBUG
#undef NDEBUG
#endif

#include <assert.h>

static BtorMemMgr *g_mm;

void
init_aigvec_tests (void)
{
  g_mm = btor_new_mem_mgr ();
}

static void
test_new_delete_aigvec_mgr (void)
{
  BtorAIGVecMgr *avmgr = btor_new_aigvec_mgr (g_mm, 0);
  btor_delete_aigvec_mgr (avmgr);
}

static void
test_const_aigvec (void)
{
  const char bits[]    = {'1', '0', '1', '1', '\0'};
  BtorAIGVecMgr *avmgr = btor_new_aigvec_mgr (g_mm, 0);
  BtorAIGVec *av       = btor_const_aigvec (avmgr, bits);
  assert (av->len == 4);
  btor_release_delete_aigvec (avmgr, av);
  btor_delete_aigvec_mgr (avmgr);
}

static void
test_var_aigvec (void)
{
  BtorAIGVecMgr *avmgr = btor_new_aigvec_mgr (g_mm, 0);
  BtorAIGVec *av       = btor_var_aigvec (avmgr, 32);
  assert (av->len == 32);
  btor_release_delete_aigvec (avmgr, av);
  btor_delete_aigvec_mgr (avmgr);
}

static void
test_not_aigvec (void)
{
  BtorAIGVecMgr *avmgr = btor_new_aigvec_mgr (g_mm, 0);
  BtorAIGVec *av1      = btor_var_aigvec (avmgr, 32);
  BtorAIGVec *av2      = btor_not_aigvec (avmgr, av1);
  assert (av2->len == 32);
  btor_release_delete_aigvec (avmgr, av1);
  btor_release_delete_aigvec (avmgr, av2);
  btor_delete_aigvec_mgr (avmgr);
}

static void
test_slice_aigvec (void)
{
  BtorAIGVecMgr *avmgr = btor_new_aigvec_mgr (g_mm, 0);
  BtorAIGVec *av1      = btor_var_aigvec (avmgr, 32);
  BtorAIGVec *av2      = btor_slice_aigvec (avmgr, av1, 17, 2);
  assert (av2->len == 16);
  btor_release_delete_aigvec (avmgr, av1);
  btor_release_delete_aigvec (avmgr, av2);
  btor_delete_aigvec_mgr (avmgr);
}

static void
test_and_aigvec (void)
{
  BtorAIGVecMgr *avmgr = btor_new_aigvec_mgr (g_mm, 0);
  BtorAIGVec *av1      = btor_var_aigvec (avmgr, 32);
  BtorAIGVec *av2      = btor_var_aigvec (avmgr, 32);
  BtorAIGVec *av3      = btor_and_aigvec (avmgr, av1, av2);
  assert (av3->len == 32);
  btor_release_delete_aigvec (avmgr, av1);
  btor_release_delete_aigvec (avmgr, av2);
  btor_release_delete_aigvec (avmgr, av3);
  btor_delete_aigvec_mgr (avmgr);
}

static void
test_ult_aigvec (void)
{
  BtorAIGVecMgr *avmgr = btor_new_aigvec_mgr (g_mm, 0);
  BtorAIGVec *av1      = btor_var_aigvec (avmgr, 32);
  BtorAIGVec *av2      = btor_var_aigvec (avmgr, 32);
  BtorAIGVec *av3      = btor_ult_aigvec (avmgr, av1, av2);
  assert (av3->len == 1);
  btor_release_delete_aigvec (avmgr, av1);
  btor_release_delete_aigvec (avmgr, av2);
  btor_release_delete_aigvec (avmgr, av3);
  btor_delete_aigvec_mgr (avmgr);
}

static void
test_eq_aigvec (void)
{
  BtorAIGVecMgr *avmgr = btor_new_aigvec_mgr (g_mm, 0);
  BtorAIGVec *av1      = btor_var_aigvec (avmgr, 32);
  BtorAIGVec *av2      = btor_var_aigvec (avmgr, 32);
  BtorAIGVec *av3      = btor_eq_aigvec (avmgr, av1, av2);
  assert (av3->len == 1);
  btor_release_delete_aigvec (avmgr, av1);
  btor_release_delete_aigvec (avmgr, av2);
  btor_release_delete_aigvec (avmgr, av3);
  btor_delete_aigvec_mgr (avmgr);
}

static void
test_add_aigvec (void)
{
  BtorAIGVecMgr *avmgr = btor_new_aigvec_mgr (g_mm, 0);
  BtorAIGVec *av1      = btor_var_aigvec (avmgr, 32);
  BtorAIGVec *av2      = btor_var_aigvec (avmgr, 32);
  BtorAIGVec *av3      = btor_add_aigvec (avmgr, av1, av2);
  assert (av3->len == 32);
  btor_release_delete_aigvec (avmgr, av1);
  btor_release_delete_aigvec (avmgr, av2);
  btor_release_delete_aigvec (avmgr, av3);
  btor_delete_aigvec_mgr (avmgr);
}

static void
test_sll_aigvec (void)
{
  BtorAIGVecMgr *avmgr = btor_new_aigvec_mgr (g_mm, 0);
  BtorAIGVec *av1      = btor_var_aigvec (avmgr, 32);
  BtorAIGVec *av2      = btor_var_aigvec (avmgr, 5);
  BtorAIGVec *av3      = btor_sll_aigvec (avmgr, av1, av2);
  assert (av3->len == 32);
  btor_release_delete_aigvec (avmgr, av1);
  btor_release_delete_aigvec (avmgr, av2);
  btor_release_delete_aigvec (avmgr, av3);
  btor_delete_aigvec_mgr (avmgr);
}

static void
test_srl_aigvec (void)
{
  BtorAIGVecMgr *avmgr = btor_new_aigvec_mgr (g_mm, 0);
  BtorAIGVec *av1      = btor_var_aigvec (avmgr, 32);
  BtorAIGVec *av2      = btor_var_aigvec (avmgr, 5);
  BtorAIGVec *av3      = btor_srl_aigvec (avmgr, av1, av2);
  assert (av3->len == 32);
  btor_release_delete_aigvec (avmgr, av1);
  btor_release_delete_aigvec (avmgr, av2);
  btor_release_delete_aigvec (avmgr, av3);
  btor_delete_aigvec_mgr (avmgr);
}

static void
test_mul_aigvec (void)
{
  BtorAIGVecMgr *avmgr = btor_new_aigvec_mgr (g_mm, 0);
  BtorAIGVec *av1      = btor_var_aigvec (avmgr, 32);
  BtorAIGVec *av2      = btor_var_aigvec (avmgr, 32);
  BtorAIGVec *av3      = btor_mul_aigvec (avmgr, av1, av2);
  assert (av3->len == 32);
  btor_release_delete_aigvec (avmgr, av1);
  btor_release_delete_aigvec (avmgr, av2);
  btor_release_delete_aigvec (avmgr, av3);
  btor_delete_aigvec_mgr (avmgr);
}

static void
test_udiv_aigvec (void)
{
  BtorAIGVecMgr *avmgr = btor_new_aigvec_mgr (g_mm, 0);
  BtorAIGVec *av1      = btor_var_aigvec (avmgr, 32);
  BtorAIGVec *av2      = btor_var_aigvec (avmgr, 32);
  BtorAIGVec *av3      = btor_udiv_aigvec (avmgr, av1, av2);
  assert (av3->len == 32);
  btor_release_delete_aigvec (avmgr, av1);
  btor_release_delete_aigvec (avmgr, av2);
  btor_release_delete_aigvec (avmgr, av3);
  btor_delete_aigvec_mgr (avmgr);
}

static void
test_urem_aigvec (void)
{
  BtorAIGVecMgr *avmgr = btor_new_aigvec_mgr (g_mm, 0);
  BtorAIGVec *av1      = btor_var_aigvec (avmgr, 32);
  BtorAIGVec *av2      = btor_var_aigvec (avmgr, 32);
  BtorAIGVec *av3      = btor_urem_aigvec (avmgr, av1, av2);
  assert (av3->len == 32);
  btor_release_delete_aigvec (avmgr, av1);
  btor_release_delete_aigvec (avmgr, av2);
  btor_release_delete_aigvec (avmgr, av3);
  btor_delete_aigvec_mgr (avmgr);
}

static void
test_concat_aigvec (void)
{
  BtorAIGVecMgr *avmgr = btor_new_aigvec_mgr (g_mm, 0);
  BtorAIGVec *av1      = btor_var_aigvec (avmgr, 16);
  BtorAIGVec *av2      = btor_var_aigvec (avmgr, 32);
  BtorAIGVec *av3      = btor_concat_aigvec (avmgr, av1, av2);
  assert (av3->len == 48);
  btor_release_delete_aigvec (avmgr, av1);
  btor_release_delete_aigvec (avmgr, av2);
  btor_release_delete_aigvec (avmgr, av3);
  btor_delete_aigvec_mgr (avmgr);
}

static void
test_cond_aigvec (void)
{
  BtorAIGVecMgr *avmgr = btor_new_aigvec_mgr (g_mm, 0);
  BtorAIGVec *av1      = btor_var_aigvec (avmgr, 1);
  BtorAIGVec *av2      = btor_var_aigvec (avmgr, 32);
  BtorAIGVec *av3      = btor_var_aigvec (avmgr, 32);
  BtorAIGVec *av4      = btor_cond_aigvec (avmgr, av1, av2, av3);
  assert (av4->len == 32);
  btor_release_delete_aigvec (avmgr, av1);
  btor_release_delete_aigvec (avmgr, av2);
  btor_release_delete_aigvec (avmgr, av3);
  btor_release_delete_aigvec (avmgr, av4);
  btor_delete_aigvec_mgr (avmgr);
}

static void
test_is_const_aigvec (void)
{
  const char bits[]    = {'1', '0', '1', '1', '\0'};
  BtorAIGVecMgr *avmgr = btor_new_aigvec_mgr (g_mm, 0);
  BtorAIGVec *av1      = btor_var_aigvec (avmgr, 1);
  BtorAIGVec *av2      = btor_const_aigvec (avmgr, bits);
  BtorAIGVec *av3      = btor_concat_aigvec (avmgr, av1, av2);
  assert (!btor_is_const_aigvec (avmgr, av1));
  assert (btor_is_const_aigvec (avmgr, av2));
  assert (!btor_is_const_aigvec (avmgr, av3));
  btor_release_delete_aigvec (avmgr, av1);
  btor_release_delete_aigvec (avmgr, av2);
  btor_release_delete_aigvec (avmgr, av3);
  btor_delete_aigvec_mgr (avmgr);
}

void
run_aigvec_tests (int argc, char **argv)
{
  BTOR_RUN_TEST (new_delete_aigvec_mgr);
  BTOR_RUN_TEST (const_aigvec);
  BTOR_RUN_TEST (var_aigvec);
  BTOR_RUN_TEST (not_aigvec);
  BTOR_RUN_TEST (slice_aigvec);
  BTOR_RUN_TEST (and_aigvec);
  BTOR_RUN_TEST (ult_aigvec);
  BTOR_RUN_TEST (eq_aigvec);
  BTOR_RUN_TEST (add_aigvec);
  BTOR_RUN_TEST (sll_aigvec);
  BTOR_RUN_TEST (srl_aigvec);
  BTOR_RUN_TEST (mul_aigvec);
  BTOR_RUN_TEST (udiv_aigvec);
  BTOR_RUN_TEST (urem_aigvec);
  BTOR_RUN_TEST (concat_aigvec);
  BTOR_RUN_TEST (cond_aigvec);
  BTOR_RUN_TEST (is_const_aigvec);
}

void
finish_aigvec_tests (void)
{
  btor_delete_mem_mgr (g_mm);
}

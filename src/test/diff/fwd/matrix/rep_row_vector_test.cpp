#include <gtest/gtest.h>
#include <stan/math/rep_row_vector.hpp>
#include <stan/diff/fwd/matrix/typedefs.hpp>
#include <stan/diff/fwd/fvar.hpp>

TEST(DiffFwdMatrix,rep_rowvector) {
  using stan::math::rep_row_vector;
  using stan::diff::row_vector_fv;
  using stan::diff::fvar;
  fvar<double> a;
  a.val_ = 3.0;
  a.d_ = 2.0;
  row_vector_fv output;
  output = rep_row_vector(a, 4);

  EXPECT_EQ(3,output(0).val_);
  EXPECT_EQ(3,output(1).val_);
  EXPECT_EQ(3,output(2).val_);
  EXPECT_EQ(3,output(3).val_);
  EXPECT_EQ(2,output(0).d_);
  EXPECT_EQ(2,output(1).d_);
  EXPECT_EQ(2,output(2).d_);
  EXPECT_EQ(2,output(3).d_);
}

TEST(DiffFwdMatrix,rep_rowvector_exception) {
  using stan::math::rep_row_vector;
  using stan::diff::row_vector_fv;
  using stan::diff::fvar;
  fvar<double> a;
  a.val_ = 3.0;
  a.d_ = 2.0;

  EXPECT_THROW(rep_row_vector(a,-2), std::domain_error);
}

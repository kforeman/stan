#include <stan/math/matrix/cols.hpp>
#include <gtest/gtest.h>
#include <stan/diff/fwd/matrix/typedefs.hpp>

TEST(DiffFwdMatrix,cols_vector) {
  using stan::diff::vector_fv;
  using stan::diff::row_vector_fv;
  using stan::math::cols;

  vector_fv v(5);
  v << 0, 1, 2, 3, 4;
   v(0).d_ = 1.0;
   v(1).d_ = 1.0;
   v(2).d_ = 1.0;
   v(3).d_ = 1.0;
   v(4).d_ = 1.0;
  EXPECT_EQ(1U, cols(v));

  v.resize(0);
  EXPECT_EQ(1U, cols(v));
}
TEST(DiffFwdMatrix,cols_rowvector) {
  using stan::diff::row_vector_fv;
  using stan::math::cols;

  row_vector_fv rv(5);
  rv << 0, 1, 2, 3, 4;
   rv(0).d_ = 1.0;
   rv(1).d_ = 1.0;
   rv(2).d_ = 1.0;
   rv(3).d_ = 1.0;
   rv(4).d_ = 1.0;
  EXPECT_EQ(5U, cols(rv));
  
  rv.resize(0);
  EXPECT_EQ(0U, cols(rv));
}
TEST(DiffFwdMatrix,cols_matrix) {
  using stan::diff::matrix_fv;
  using stan::math::cols;

  matrix_fv m(2,3);
  m << 0, 1, 2, 3, 4, 5;
  m(0,0).d_ = 1.0;
  EXPECT_EQ(3U, cols(m));
  
  m.resize(5, 0);
  EXPECT_EQ(0U, cols(m));
}

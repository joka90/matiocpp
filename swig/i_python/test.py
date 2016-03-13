from matio import Mat, MatVar
import matio

mat = Mat()

mat.Open('../../datasets/matio_test_cases_uncompressed_be.mat',matio.acc_MAT_ACC_RDONLY)

mat.PrintVars()


"""dir(Mat)

dir(MatVar)
"""

v = mat.Read("var50")
dir(v)

v.Print(0)




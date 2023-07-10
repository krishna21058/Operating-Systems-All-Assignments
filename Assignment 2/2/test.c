#include <stdio.h>
#include <sys/syscall.h>
#include <linux/kernel.h>
#include <unistd.h>
#include <errno.h>

#define TWOD_COPY_SYSCALL 451

void check_equal(int size,int lhs[][size], int rhs[][size])
{
    int i;
    for (i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (lhs[i][j] != rhs[i][j])
            {
                printf("Error : LHS[%d][%d] != RHS[%d][%d]\n", i,j,i,j);
                return;
            }
        }
    }
    printf("Message : Success LHS = RHS \n");
}
int main()
{
    int src_arr[2][2] = {{1,2},{1,2}};
    int dest_arr[2][2];

    long sys_call_status = syscall(TWOD_COPY_SYSCALL, src_arr, dest_arr, 10);

    if (sys_call_status != EFAULT)
    {
        printf("Message : System Call 451 successfuly invoked \n");
        check_equal(2,src_arr, dest_arr);
    }

    return 0;
}

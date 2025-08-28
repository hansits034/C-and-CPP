# include <stdio.h>

int main (){
    int input, ans, i, ngon;
    ans=0;
    scanf("%d %d", &ngon, &input);
    ans=ans+ngon*input;
    printf("%d\n", ans);
    for(i=input-1;i>0;i--){
        ans=ans+(ngon-2)*i-1;
    }
    printf("%d", ans);
    return 0;
}

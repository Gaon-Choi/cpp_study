# Exercise 2

**<문제>**

다음은 int형 배열에 저장된 값을 모두 더해서 그 결과를 반환하는 기능의 함수이다.


```cpp
int SumArray(int arr[], int len) {
  int sum=0;
  for(int i = 0; i < len; i++)
    sum+=arr[i];
  return sum;
}
```


이 함수를 템플릿으로 정의하여, 다양한 자료형의 배열을 대상으로 합을 게산하는 예제를 작성해보자.

/**
 * 두 배열의 값을 2로 나누면서 나머지를 구합니다(2진수를 구하는 나눗셈). 두 배열의 요소 중 하나라도 나머지 값이 1이면 '#' 아니면 ' '로 문자를 만듭니다.
 * 이진수로 만들면 값이 거꾸로 만들어지기 때문에 새로 만든 문자를 기존의 문자 앞에 붙입니다.
*/

#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    for (int i = 0; i < arr1.size(); i++) {
        int result = arr1[i] | arr2[i];
        for (int j = 0; j < n; j++) {
            string c = result % 2 == 0 ? " " : "#";
            result /= 2;
            answer[i] = c + answer[i];
        }            
    }
    
    return answer;
}

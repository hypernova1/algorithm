/*
    일단 최대한 단순하게 풀었는데 정답 처리가 되었다. 하지만 이게 진짜 정답이 맞는지는 좀 의문이 든다..
    
    풀이
        i를 1부터 n까지 돌면서 시작하는 수를 1씩 증가시켜 가며 더해준다. 그 더해진 값이 n과 같으면 answer을 1 증가 시킨다.
*/

int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = i; j <= n; j++) {
            sum += j;
            if (sum > n) break;
            if (n == sum) {
                answer++;
            }
        }
    }
    return answer;
}
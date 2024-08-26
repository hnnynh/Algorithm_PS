using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    double start = 0, end = 0;
    
    if(w == h)
        return (long long)w * h - w;
    if(w == 1 || h == 1)
        return 0;
    
    for(long long i=1; i<=w; i++){
        end = h * i / (double)w;
        for(long long j=start; j<end; j++)
            answer--;

        start = end;
    }
    
    answer += (long long)w * h;
    
    return answer;
}

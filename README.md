# 42_GetNextLine

## Mandatory Part 구상
1. cache가 있으면, buff에 붙이기 
    - buff 안에 \n 확인 -> 있으면, 4번 실행
    - 없으면, 다음 진행
2. buff 안에 BUFFER_SIZE 만큼 읽어서 넣기 
3. 만일 buff안에 \n 이 없으면, 다시 BUFFER_SIZE만큼 읽어서 buff에 붙이기 (반복)
4. buff 안에 \n 이 있으면, buff의 \n 까지를 line에 복사하기
5. \n 뒤에서 부터 읽어들인 곳 까지 cache에 담기
6. line을 return 하기 
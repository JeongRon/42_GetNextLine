# 42_GetNextLine

## 1. Mandatory Part 구상
1. cache가 있으면, buff에 붙이기 
    - buff 안에 \n 확인 -> 있으면, 4번 실행
    - 없으면, 다음 진행
2. buff 안에 BUFFER_SIZE 만큼 읽어서 넣기 
3. 만일 buff안에 \n 이 없으면, 다시 BUFFER_SIZE만큼 읽어서 buff에 붙이기 (반복)
4. buff 안에 \n 이 있으면, buff의 \n 까지를 line에 복사하기
5. \n 뒤에서 부터 읽어들인 곳 까지 cache에 담기
6. line을 return 하기 

---

## 2. Mandatory Part 구현
### get_next_line.c
- char	*make_buff(char *buff, int fd);
    - \n 이 나올 때까지 BUFFER_SIZE 만큼 buff를 만드는 함수
- int	check_buff(char *buff);
    - buff 안에 \n 있는지 확인하는 함수
- char	*make_line(char *buff, int line_len);
    - line을 만드는 함수
- char	*make_cache(char *buff, int line_len, int buff_len);
    - cache를 만드는 함수
- char	*get_next_line(int fd);
    - line을 궁극적으로 리턴 하는 함수

### get_next_line_utils.c
- char	*ft_strdup(const char *src);
    - src 문자열을 복사(할당)해서 리턴하는 함수
- int	ft_strlen(const char *s);
    - 문자열의 길이를 재는 함수 
- int	ft_linelen(const char *s);
    - \n 까지의 길이를 재는 함수
- char	*ft_strjoin(char *join_buff, char *tmp, int tmp_len);
    - join_buff 문자열과 tmp 문자열을 붙여서 리턴하는 함수

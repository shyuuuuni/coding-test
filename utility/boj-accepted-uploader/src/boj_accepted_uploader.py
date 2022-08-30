# -*- coding: utf-8 -*-
import psutil
import webbrowser
import time
import argparse
import os

# 프로그램 인자를 파싱
parser = argparse.ArgumentParser(description='arguparser')
parser.add_argument('--boj_id', required=True,
                    help='백준 온라인 저지 아이디를 입력합니다.')
parser.add_argument('--ac', required=False, default='accepted.txt',
                    help='https://www.acmicpc.net/user/[boj_id]에 표시되는 맞은 문제 목록을 복사한 파일의 이름을 입력합니다.')
parser.add_argument('--begin', required=False, default=0,
                    help='시작 할 문제 번호를 입력합니다. 입력하지 않으면 처음부터 진행합니다.')

# psutil 라이브러리를 사용하여 이름이 "Google Chrome"인 프로세스 종료
def kill_chrome():
    try:
        for proc in psutil.process_iter():
            if proc.name() == "Google Chrome":
                proc.kill()
    except (psutil.AccessDenied, psutil.NoSuchProcess, OSError):
        pass

# 프로그램 실행 시 안내사항을 출력한다.
def print_docs(args):
    print("======================================================================================================")
    print("위 프로그램은 백준허브(https://github.com/BaekjoonHub/BaekjoonHub)를 지원하기 위한 프로그램으로,")
    print("현재 계정의 백준 온라인 저지 계정이 제출하여 정답 처리 된 문제들을 백준허브 확장 프로그램을 적용합니다.")
    print("")
    print("사용 전 확인사항")
    print(" V 크롬 확장프로그램으로 백준허브 확장을 추가해야 합니다.")
    print(" V 크롬 브라우저로 백준 온라인 저지 사이트 로그인 시 '로그인 상태 유지'를 체크하고 로그인하는 것을 추천합니다.")
    print(" V 실행 전 다른 크롬 브라우저는 종료하는 것을 추천합니다.")
    print(" V 마지막으로 입력 데이터(백준 아이디={0}, 시작 문제 번호={1}, 맞은 문제 목록={2} 등) 가 정확한지 확인하세요.".format(args.boj_id, args.begin, args.ac))
    print("======================================================================================================")

# 맞은 문제들을 탐색하면서 백준허브 확장 프로그램을 적용합니다.
def run(args):
    boj_id = args.boj_id
    begin_no = args.begin
    ac_list = args.ac

    # 맞은 문제 번호를 파일에서 가져온다.
    f = open(ac_list, 'r')
    rawdata = f.readline().split()
    f.close()

    # begin_no 이상의 번호에 대해서만 가져온다.
    data = list(filter(lambda x: int(begin_no)<=int(x), rawdata))

    # M1 MAC OS
    chromepath = "open -a /Applications/Google\ Chrome.app %s"

    # Windows
    prgm_path = os.environ.get("PROGRAMFILES").replace('\\', '/')
    chromepath = prgm_path + '/Google/Chrome/Application/chrome.exe %s'

    cnt = 0 # 10번 반복 마다 chrome 창을 종료한다.
    for problem_no in data:
        print('\r 현재 {} 번 진행중 ...'.format(problem_no))
        url = 'https://www.acmicpc.net/status?from_mine=1&problem_id={0}&user_id={1}'.format(problem_no, boj_id)
        webbrowser.get(chromepath).open(url)
        
        time.sleep(22) # 확장 프로그램 실행 시간, 크롬 종료 시간 등 대기
        cnt = cnt + 1
        if cnt % 10 == 0:
            kill_chrome()

if __name__ == '__main__':
    args = parser.parse_args()
    print_docs(args)
    run(args)
# C 프로그램으로 시스템의 사용 가능한 RAM 용량 확인하기

이 프로그램은 Linux 시스템에서 사용 가능한 RAM 용량을 확인하는 C 프로그램입니다. 이 프로그램은 다음과 같은 기능을 제공합니다:

1. `/proc/meminfo` 파일에서 "MemFree" 값을 읽어와 사용 가능한 RAM 용량을 bytes 단위로 반환합니다.
2. 사용 가능한 RAM 용량을 KB, MB, GB, TB단위로 변환하여 출력합니다.
3. 사용 가능한 RAM 용량 확인에 실패할 경우 오류 메시지를 출력하고 프로그램을 종료합니다.

## 컴파일 및 실행 방법

이 프로그램을 컴파일하고 실행하는 방법은 다음과 같습니다:

1. 소스 코드 파일을 다운로드합니다:
   ```
   git clone https://github.com/ChanHyeok8207/ch.jeon.git
   ```

2. 디렉토리로 이동합니다:
   ```
   cd ch.jeon
   ```

3. 프로그램을 컴파일합니다:
   ```
   gcc -o freeram freeram.c proc_freeram.c
   ```

4. 컴파일된 프로그램을 실행합니다:
   ```
   ./freeram
   ```

프로그램이 실행되면 사용 가능한 RAM 용량이 bytes, KB, MB, GB, TB 단위로 출력됩니다.

## 단위 테스트

이 프로그램에는 `freeram_test.c` 파일에 단위 테스트 코드가 포함되어 있습니다. 이 테스트 코드를 실행하면 `convert_bytes()` 함수의 동작을 확인할 수 있습니다. 단위 테스트를 실행하는 방법은 다음과 같습니다:

1. 의존성 라이브러리를 설치합니다:
   ```
   sudo apt-get install -y cmake
   ```

2. 테스트 코드를 컴파일하고 실행합니다:
   ```
   mkdir build
   cd build
   cmake ..
   make
   ./freeram_test
   ```

이 명령어를 실행하면 `convert_bytes()` 함수의 단위 테스트가 실행되고, 테스트 결과가 출력됩니다. 

# WNixalo 2017-Nov-22 15:53

def main():
    from time import time, sleep
    from sys import stdout

    stdout.write("\r")
    stdout.flush()
    print()

    total_time = float(input("Time (minutes): ")) * 60
    last_time = time()

    elapsed_time = 0.

    print()

    while elapsed_time <= total_time:
        stdout.write("\r")

        clock_time = total_time - elapsed_time

        H = int((clock_time) / 3600)
        M = int(((clock_time) - H*3600) / 60)
        S = int(clock_time - H*3600 - M*60)

        stdout.write(f'Time Left {H:0=2d}:{M:0=2d}:{S:0=2d}')
        stdout.flush()

        last_time = time()
        sleep(1)
        elapsed_time += time() - last_time

    print("Countdown End")

if __name__ == '__main__':
    main()

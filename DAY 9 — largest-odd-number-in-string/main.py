
def largest_odd(num: str):
    return num[:1 + max(num.rfind(c) for c in '13579')]


if __name__ == "__main__":
    print(largest_odd("10133890"))

    ...

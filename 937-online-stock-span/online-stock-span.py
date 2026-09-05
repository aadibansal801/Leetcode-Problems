class StockSpanner:

    def __init__(self):
        self.st = []

    def next(self, price: int) -> int:
        span = 1
        while self.st:
            oldprice, oldspan = self.st[-1]
            if oldprice <= price:
                self.st.pop()
                span+=oldspan
            else:
                break
        self.st.append((price, span))
        return span

        


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
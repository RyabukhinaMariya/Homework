def curring(func, arity):
        def curried(*args):
            if len(args) >= arity:
                if arity != len(args):
                    raise TypeError(f'Expected {arity} arguments, got {len(args)}')
                return func(*args)
            return lambda *more_args: curried(*(args+more_args))
        return curried

def uncurring(func, arity):
        def uncurried(*args):
            if arity != len(args):
                raise TypeError(f'Expected {arity} arguments, got {len(args)}')
            res = func
            for arg in range(arity):
                res = res(args[arg])
            return res
        return uncurried

arity = 4
def sum(a, b, c, d):
    return a+b+c+d

sum = curring(sum, arity)
print(sum(1)(2)(3)(4))

sum = uncurring(sum, arity)
print(sum(1, 2, 3, 4))
  

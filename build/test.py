import monte_carlo_pricer as mcp
import math

# 1. Setup Parameters
spot = 100.0
strike = 105.0
expiry = 1.0      # 1 year
vol = 0.2         # 20%
risk_free = 0.05  # 5%
paths = 100000

# 2. Initialize the C++ Components
# GBMPathGenerator(spot, expiry, vol, risk_free)
path_gen = mcp.GBMPathGenerator(spot, risk_free, vol, expiry)
call_option = mcp.EuropeanCall(strike)

# 3. Setup the Engine
# PricerEngine(expiry, risk_free, num_paths)
engine = mcp.PricerEngine(risk_free, expiry, paths)

# 4. Run Simulation
stats = engine.runSimulation(path_gen, call_option)

print(f"Option Price: {stats.getMean():.4f}")
print(f"Std Error:    {stats.getStdError():.4f}")
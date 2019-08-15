import matplotlib.pyplot as plt
import pandas as pd
import os

if __name__ == "__main__":
    for fname in os.listdir("data"):
        try:
            df = pd.read_csv("data/"+fname)
            obv = df.columns[-1]

            fig = plt.figure()
            axes = fig.add_axes([0.05,0.05,0.9,0.9])
            axes.plot(df[obv], df.result)
            fig.savefig("pics/" + fname[:-4]+"_Res.png")
            fig = plt.figure()
            axes = fig.add_axes([0.05,0.05,0.9,0.9])
            axes.plot(df[obv], df.std_err)
            fig.savefig("pics/" + fname[:-4]+"_Err.png")
            fig = plt.figure()
            axes = fig.add_axes([0.05,0.05,0.9,0.9])
            axes.plot(df[obv], df.time_usage)
            fig.savefig("pics/" + fname[:-4]+"_Tme.png")
        except Exception as e:
            print(e)
            pass
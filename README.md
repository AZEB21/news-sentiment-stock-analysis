# news-sentiment-stock-analysis
This project explores the relationship between financial news sentiment and stock price movements using the FNSPID dataset. 
It performs Exploratory Data Analysis (EDA) on news headlines, computes technical indicators for stock prices, and lays the groundwork for sentiment-based trading insights.
## Dataset
- **FNSPID (Financial News and Stock Price Integration Dataset)**
- Contains news headlines, publisher info, timestamps, and stock tickers.
- Used to analyze sentiment and its potential impact on stock price movements.
## Features
1. Environment setup with Python, virtual environment, and GitHub.
2. Exploratory Data Analysis (EDA) on financial news headlines:
   - Headline lengths
   - Publisher activity
   - Publishing times and topic trends
3. Calculation of technical indicators using TA-Lib:
   - SMA (Short/Long)
   - RSI
   - MACD
4. Sentiment analysis (planned in Task-3 using TextBlob/VADER)
5. Correlation analysis between news sentiment and stock price movements (upcoming)
## Repository Structure
├── README.md
├── requirements.txt
├── src/
│   ├── sentiment.py
│   ├── data_cleaning.py
│   └── indicators.py
├── notebooks/
│   ├── 01_EDA.ipynb
│   └── 02_Indicators.ipynb
├── tests/
└── .github/workflows/unittests.yml
## Installation
1. Clone the repository:
2. Navigate to the project folder:
4. Activate the environment:
- Windows:
  ```
  .\.venv\Scripts\activate
  ```
- Mac/Linux:
  ```
  source .venv/bin/activate
  ```
5. Install dependencies:
6. Launch Jupyter Notebook:
## Usage
- Open `notebooks/01_EDA.ipynb` to explore news data and perform EDA.
- Open `notebooks/02_Indicators.ipynb` for stock technical analysis.
## Next Steps
- Perform sentiment analysis on headlines using TextBlob and VADER.
- Align news data with stock trading days.
- Calculate correlation between sentiment and stock price returns.
- Prototype potential trading strategies based on sentiment thresholds.
## Author
**Azeb Yirga**

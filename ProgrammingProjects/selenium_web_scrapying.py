from selenium import webdriver

website="https://www.google.com"
path="C:\chrome-win64\chrome.exe"
driver=webdriver.Chrome(path)


driver.get(website)

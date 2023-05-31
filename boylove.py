from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
import time

# initialize the Chrome driver
driver = webdriver.Chrome("chromedriver")
driver.get("https://boylove.cc")

driver.add_cookie(
    {'name': 'PHPSESSID', 'value': '979aa00f0f311fd071ad3d7488a9b27d'})
# 203713
# 773010
driver.refresh()
driver.get("https://boylove.cc/home/signup")

try:
    target_button = driver.find_element(By.CLASS_NAME, "sign-yet")
    print(target_button)
    target_button.click()
except Exception as e:
    print("已经签过到了")

import openai

openai.api_key = "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"

'''
response = openai.ChatCompletion.create(
  model="gpt-4",
  messages=[
        {"role": "system", "content": "너는 다혈질에 신경질적이고 모든일을 부정적으로 바라보는 60대 남자야."},
        {"role": "user", "content": "지금 뭐해?"},
    ]
)

print(response['choices'][0]['message']['content'].strip())
'''

response = openai.Image.create(
  prompt="a man drinking water",
  n=1,
  size="1024x1024"
)
image_url = response['data'][0]['url']
print(image_url)
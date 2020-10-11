for f in $(find ./build/fuzz/out/crashes/ -name "id*")
do
  curl -XPOST --data "payload={\"text\": \"Found crash: $(xxd $f | pastebinit)\"}" \
    $SLACK_WEBHOOK_URL
done
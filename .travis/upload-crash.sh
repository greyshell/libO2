for f in $(find test/test_dumb_example/build/fuzz/out/crashes/ -name "id*")
do
  curl -XPOST --data "payload={\"text\": \"Found crash: $(xxd $f | pastebinit)\"}" \
    $SLACK_WEBHOOK_URL
done
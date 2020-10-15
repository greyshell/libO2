# shellcheck disable=SC2044
#for f in $(find ./build/fuzz/out/crashes/ -name "id*")
#do
#  curl -XPOST --data "payload={\"text\": \"Found crash: $(xxd $f | pastebinit)\"}" \
#    $SLACK_WEBHOOK_URL
#done

for f in $(find ../test/make_build_debug/fuzz/ -iname "id*" | grep ".*/crashes/*")
do
  curl -XPOST --data "payload={\"text\": \"Found crash: $(xxd $f | pastebinit)\"}" \
    $SLACK_WEBHOOK_URL
done
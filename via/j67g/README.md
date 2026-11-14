# j67g (VIA)

j67g のファームウェアはこのリポジトリではビルドしない。キーマップとマクロは VIA で設定し、VIA のレイアウトエクスポートとしてここに保存する。

| ファイル           | 内容                                                       |
| ------------------ | ---------------------------------------------------------- |
| `j67g.layout.json` | VIA の「Save Current Layout」で書き出したもの(4 レイヤー、マクロ 16 枠) |
| `definition.json`  | VIA V3 のキーボード定義。usevia.app で j67g を開くのに要る |

`definition.json` は、メーカーの V2 定義(<https://github.com/Salicylic-acid3/via-json/blob/main/j67g.json>)から `"lighting"` を消し、`"menus": []` と `"keycodes": []` を足して作った。レイアウトは変えていない。

## マクロ

| 枠         | シーケンス          | 動作                   |
| ---------- | ------------------- | ---------------------- |
| `MACRO(0)` | `{KC_MHEN}{KC_ESC}` | 無変換を押してから Esc |
| `MACRO(1)` | `{KC_MINS}>`        | `->` を入力する        |

どちらもレイヤー 1 に割り当てている。

## 必要なもの

- Chromium 系のブラウザ。VIA は WebHID と `showSaveFilePicker` を使う。
- usevia.app には j67g(VID `0x04D8`、PID `0xE64B`)の公式定義がない。ファームウェアは VIA プロトコル 12 で通信するため、VIA には V3 定義が要る。V2 定義を読み込んでも無視される。

## 定義を読み込む(ブラウザごとに 1 回)

1. <https://usevia.app> を開き、**Settings** で **Show Design tab** を有効にする。
2. **Design** タブで **Use V2 definitions** をオフにし、**Load** で `definition.json` を読み込む。

読み込んだ定義はブラウザ(IndexedDB)に残る。

## バックアップ

1. j67g をつなぎ、VIA で接続を許可する。
2. **SAVE + LOAD** → **Save Current Layout** を選ぶ。
3. `j67g.layout.json` をそのまま上書きしてコミットする。履歴は Git に残るので、日付つきのコピーは作らない。

## 復元

1. j67g をつなぎ、VIA で接続を許可する。
2. **SAVE + LOAD** → **Load Saved Layout** で `j67g.layout.json` を選ぶ。ファイルのマクロ数がキーボードの枠数(16)と同じでないと読み込めない。

## エクスポートに含まれない設定

VIA のレイアウトエクスポートに入るのは `layers`、`macros`、`encoders` だけで、ライティングとレイアウトオプションは保存されない。

メーカーが勧める Remap(<https://remap-keys.app>)でも j67g を設定できる。ただし Remap のアカウントに保存したキーマップには、キーコード、エンコーダー、レイアウトオプションしか入らず、マクロの中身は入らない。VIA のエクスポートを正とする。

## トラブルシューティング

- 「Loading...」が終わらず、各コマンドへの応答が 1 つ前のコマンドのものになるエラーが出る場合は、別のタブやアプリが同時にキーボードと通信している。ほかの VIA/Remap のタブを閉じ、キーボードを挿し直してページを再読み込みし、接続をもう一度許可する。

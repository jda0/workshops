/* globals ClipboardJS, Node, Element, CharacterData, DocumentType */
// from: https://github.com/jserz/js_piece/blob/master/DOM/ChildNode/after()/after().md
(function (arr) {
  arr.forEach(function (item) {
    if (item.hasOwnProperty('after')) return
    Object.defineProperty(item, 'after', {
      configurable: true,
      enumerable: true,
      writable: true,
      value: function after () {
        let argArr = Array.prototype.slice.call(arguments)
        let docFrag = document.createDocumentFragment()

        argArr.forEach(function (argItem) {
          var isNode = argItem instanceof Node
          docFrag.appendChild(isNode ? argItem : document.createTextNode(String(argItem)))
        })

        this.parentNode.insertBefore(docFrag, this.nextSibling)
      }
    })
  })
})([Element.prototype, CharacterData.prototype, DocumentType.prototype])

document.addEventListener('DOMContentLoaded', function () {
  function clearTooltip (el) {
    console.log('l')
    el.setAttribute('class', 'clippy')
    el.removeAttribute('aria-label')
  }

  function showTooltip (el, msg) {
    el.setAttribute('class', 'clippy tooltipped tooltipped-n')
    el.setAttribute('aria-label', msg)
    // setTimeout(function () { clearTooltip(el) }, 600)
  }

  function fallbackMessage (action) {
    let actionMsg = ''
    let actionKey = (action === 'cut' ? 'X' : 'C')
    if (/iPhone|iPad/i.test(navigator.userAgent)) actionMsg = 'No support :('
    else if (/Mac/i.test(navigator.userAgent)) actionMsg = 'Press ⌘-' + actionKey + ' to ' + action
    else actionMsg = 'Press Ctrl-' + actionKey + ' to ' + action
    return actionMsg
  }

  if (ClipboardJS) {
    [].forEach.call(document.querySelectorAll('code'), (el) => {
      let copyBtn = document.createElement('a')
      copyBtn.setAttribute('class', 'clippy')
      copyBtn.innerHTML = '<i></i>'
      el.after(copyBtn)
      el.setAttribute('class', el.getAttribute('class') + ' clip-target')

      copyBtn.addEventListener('mouseleave', function (e) { clearTooltip(e.currentTarget) })
      copyBtn.addEventListener('blur', function (e) { clearTooltip(e.currentTarget) })
    })

    let clipboard = new ClipboardJS('.clippy', {
      target: function (trigger) {
        return trigger.previousSibling
      }
    })

    clipboard.on('success', function (e) {
      e.clearSelection()
      showTooltip(e.trigger, 'Copied!')
    })

    clipboard.on('error', function (e) {
      fallbackMessage(e.action)
    })
  }
})

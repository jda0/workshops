document.addEventListener('DOMContentLoaded', function () {
  let spoilern = 0

  ;[].forEach.call(document.querySelectorAll('.spoiler'), el => {
    el.setAttribute('data-spoiler', ++spoilern)

    let spoilerLink = document.createElement('a')
    spoilerLink.setAttribute('class', '.requisite-warning .warning .compact spoiler-link')
    spoilerLink.setAttribute('data-spoil', spoilern.toString())
    spoilerLink.setAttribute('href', 'javascript:void(0)')
    spoilerLink.innerHTML = el.getAttribute('data-spoiler-text') || 'At DigiMakers events, this has already been done for you. <em>Click to show anyway</em>'
    spoilerLink.addEventListener('click', e => {
      // @ts-ignore
      let target = document.querySelector('[data-spoiler="' + e.target.getAttribute('data-spoil') + '"]')
      target.setAttribute('class', target.getAttribute('class').replace(/spoiler-hidden/g, ''))
      // @ts-ignore
      e.target.parentNode.removeChild(e.target)
    })

    el.parentNode.insertBefore(spoilerLink, el)
    el.setAttribute('class', el.getAttribute('class') + ' spoiler-hidden')
  })
})
